#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

int len;
int **data;
bool **cp_data;
 
int nextt[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
int result[25];

// int cp_print(){
//     cout<<"------cp------------"<<endl;
//     for (int i=0;i<len;i++){
//         for (int j=0;j<len;j++){
//             cout<<cp_data[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }
int dfs(int i,int j,int dangi){
    // cout<<"dfs: ("<<i<<" , "<<j<<" ) num: "<<dangi<<endl;
    // cp_print();
    cp_data[i][j]=true;
    result[dangi]+=1;

    for (int k=0;k<4;k++){
        int nexti=i+nextt[k][0];
        int nextj=j+nextt[k][1];
        if (0<=nexti and nexti<len and 0<=nextj and nextj<len and data[nexti][nextj]==1 and cp_data[nexti][nextj]==false){
            //cout<<"next: ("<<nexti<<" , "<<nextj<<" ) num: "<<dangi<<endl;
            dfs(nexti,nextj,dangi);
        }
    }
    return 0;
}
// int print(){
//     cout<<"-------------"<<endl;
//     for (int i=0;i<len;i++){
//         for (int j=0;j<len;j++){
//             cout<<data[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     return 0;
// }


int main(void){

    cin>>len;
    if (len<5 or len>25) return 0;

    data=new int*[len];
    for(int i=0;i<len;i++){
        data[i]=new int[len];
        memset(data[i],0,sizeof(int)*len);
    }

    cp_data=new bool*[len];
    for(int i=0;i<len;i++){
        cp_data[i]=new bool[len];
        memset(cp_data[i],false,sizeof(bool)*len);
    }

    //input
    for (int i=0;i<len;i++){
        string s;
        cin>>s;
        for (int j=0;j<len;j++){
            data[i][j]=stoi(s.substr(j,1));
        }
    }

    // print();
    // cp_print();
    int cnt=0;
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            if (cp_data[i][j]==false and data[i][j]==1){
                dfs(i,j,cnt);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    int min_res;
    for (int i=0;i<cnt;i++){
        min_res=1000;
        for (int j=0;j<cnt;j++){
            if (min_res>result[i]){
                min_res=min(min_res,result[j]);
                result[j]=10000;
            }
        }
        cout<<min_res<<endl;
    }
    return 0;

}