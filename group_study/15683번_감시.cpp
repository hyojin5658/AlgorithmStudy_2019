#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;
int N,M;
int cctv_num;   //cctv의 총 개수
int room[8][8]; //데이터 배열 
int cpy_room[8][8];
struct cctv{
    int x;
    int y;
    int num;    //cctv의 종류 
};
int max_combi[5]={4,2,4,4,1} ;    //가지수는 몇개인지 
vector<cctv> cctvs; //cctv 위치 저장
int **cctv_combi;
int combi; //cctv 위치 조합 경우의 수 
int print_cctv_combi(){
    cout<<"print"<<endl<<endl;
    for(int i=0;i<combi;i++){
        for (int j=0;j<cctv_num;j++){
            cout<<cctv_combi[i][j]<<" ";
        }
        cout<<endl;
    }
}

int bt(int cctv_num, int checked_bt,int current_cctv, int _max_combi){ 
    if (checked_bt==cctv_num){
        return 0;
    }
    //  print_cctv_combi();
    cout<<"bt:(cctv_num, checked_bt, current_cctv, max_combi)"<<cctv_num <<" "<< checked_bt <<" "<< current_cctv<<" "<< _max_combi  <<endl;;
    for(int i=1;i<_max_combi;i++){
        cctv_combi[i][current_cctv]=cctv_combi[i-1][current_cctv]+1;
        int next_cctv=current_cctv+1;
        bt(cctv_num,checked_bt,next_cctv,max_combi[next_cctv]);
    }

}

int findSafeArea(){
    int cnt=0;
     for (int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(cpy_room[i][j]==0) cnt++;
            }
        }
    return cnt;
}

int main(){
    cin>>N>>M;

    cctv_num=0;
    combi=1;
    for (int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>room[i][j];
            if(room[i][j]>=1 && room[i][j]<=5){
                cctvs.push_back({i,j,room[i][j]-1});
                cctv_num++;
                combi=combi*max_combi[room[i][j]-1];
            }
        }
    }
    
    cctv_combi=new int*[combi];
    for(int i=0;i<combi;i++){
        cctv_combi[i]=new int[cctv_num];
        memset(cctv_combi[i],0,sizeof(int)*cctv_num);
    }
    // print_cctv_combi();
    bt(cctv_num, 0,0,max_combi[0]);
    print_cctv_combi();
    int min_res;
    //조합 하나씩 돌면서 계산
    for(int i=0;i<combi;i++){
        for (int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cpy_room[i][j]=room[i][j];
            }
        }
        // calc(combi);
        int result= findSafeArea();
        min_res=min(min_res,result);
        
    }
    cout<<min_res;
    return 0;
}