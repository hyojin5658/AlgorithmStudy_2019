#include<iostream>
#include<string.h>
#include<vector>

int n,m,h;
bool **data_in, **data_cp;
using namespace std;

struct combis{
    int num;
    pair<int,int> datas[3];
};
vector<combis> v;
int *combi_array;
bool **data_tmp;

int find(){
    //하나씩 길 검사 
    for(int i=0;i<n;i++){
        // cout<<"bar"<<i<<" start! "<<endl;
        int x=0;
        int y=i;
        while(x<h){
            // cout<<"PATH:"<<x<<" , "<<y;
            //1. 오른쪽으로 가는 경우 
            if(data_tmp[x][y]==true){
                // cout<<"go right"<<endl;
                y+=1;
                x+=1;
            }
            //2. 왼쪽으로 가는 경우 
            else if(y>=1 and data_tmp[x][y-1]==true){
                // cout<<"go left"<<endl;;
                y-=1;
                x+=1;
            }
            else{
                x+=1;
            }
        }
        if(y!=i){
            // cout<<"bar"<<y<<" end! "<<endl;
            return -1;
        } 

    }
    // cout<<"bar"<<"same"<<" end! "<<endl;
    return 1;
}

// int print_in(){
//     cout<<"---------in----------------"<<endl;
//      //사다리 출력 
//     for (int i=0;i<h;i++){
//         for (int j=0;j<n;j++){
//             cout<<data_in[i][j];
//         }
//         cout<<endl;
//     }
//     cout<<"------------------------------"<<endl;
// }
// int print_tmp(){
//     cout<<"---------tmp----------------"<<endl;
//      //사다리 출력 
//     for (int i=0;i<h;i++){
//         for (int j=0;j<n;j++){
//             cout<<data_tmp[i][j];
//         }
//         cout<<endl;
//     }
//     cout<<"------------------------------"<<endl;
// }

int find_path(){
    int cnt=0;
    combis pos_tmp;
    for(int num=0;num<v.size();num++)
    {
        //map 복사 
        for (int i=0;i<h;i++){
            for (int j=0;j<n;j++){
                data_tmp[i][j]=data_cp[i][j];
            }
        }
        if(find()>0){return 0;}
        //vector의 사다리 추가 
        pos_tmp=v.at(num);
        for (int k=0;k<pos_tmp.num;k++){
            int x=pos_tmp.datas[k].first;
            int y=pos_tmp.datas[k].second;
            data_tmp[x][y]=true;
        }
        // print_tmp();

        if(find()>0){
            cnt++;
            // cout<<"count!!!!====:"<<cnt<<endl;
            return pos_tmp.num;
        }
    }
    return -1;
}


int find_combi(){
    int first_cnt=0;
    //1개 일때 조합 집어 넣기 
    for (int i=0;i<h;i++){
        for (int j=0;j<n;j++){
            if (data_in[i][j]==false){
                combis tmp;
                tmp.num=1;
                tmp.datas[0]={i,j};
                v.push_back(tmp);
                first_cnt++;
            }
        }
    }
    //2개 일때 조합 집어 넣기
    for (int i=0;i<first_cnt-1;i++){
        combis tmp;
            tmp.num=2;
            tmp.datas[0]={v.at(i).datas[0].first,v.at(i).datas[0].second};
        for (int j=i+1;j<first_cnt;j++){
            tmp.datas[1]={v.at(j).datas[0].first,v.at(j).datas[0].second};
            v.push_back(tmp);
        }
    }
    //3개 일때 조합 집어 넣기 
    for (int i=0;i<first_cnt-2;i++){
        combis tmp;
            tmp.num=3;
            tmp.datas[0]={v.at(i).datas[0].first,v.at(i).datas[0].second};
        for (int j=i+1;j<first_cnt-1;j++){
            tmp.datas[1]={v.at(j).datas[0].first,v.at(j).datas[0].second};
            for (int k=j+1;k<first_cnt;k++){
                tmp.datas[2]={v.at(k).datas[0].first,v.at(k).datas[0].second};
                v.push_back(tmp);
            }
        }
    }
}



int main(void){
    cin>>n>>m>>h;
    data_in=new bool*[h];
    data_cp=new bool*[h];
    data_tmp=new bool*[h];
    for (int i=0;i<h;i++){
        data_in[i]=new bool[n];
        data_cp[i]=new bool[n];
        data_tmp[i]=new bool[n];
        memset(data_in[i],false,sizeof(bool)*(n));
        memset(data_cp[i],false,sizeof(bool)*(n));
        memset(data_tmp[i],false,sizeof(bool)*(n));
    }
    combi_array=new int[h];
    memset(combi_array,-1,sizeof(int)*h);
    //사다리 입력
    for (int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        data_cp[x-1][y-1]=true;
        data_in[x-1][y-1]=true;
        if (1<=y and y<n){data_in[x-1][y]=true;}
        if (y>=2){data_in[x-1][y-2]=true;}
    }

    // print_in();
   
    find_combi();
    int result=find_path();
    cout<<result;

    
    
    return 0;
}