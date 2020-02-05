#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int len;
int **data;
bool **cp_data;
 
int nextt[4][2]={{0,1},{1,0},{0,-1},{-1,0}}; 
int result[313];


int dfs(int i,int j,int dangi){
    cp_data[i][j]=true;
    result[dangi]+=1;

    for (int k=0;k<4;k++){
        int nexti=i+nextt[k][0];
        int nextj=j+nextt[k][1];
        if (0<=nexti and nexti<len and 0<=nextj and nextj<len and data[nexti][nextj]==1 and cp_data[nexti][nextj]==false){
            dfs(nexti,nextj,dangi);
        }
    }
    return 0;
}

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

    sort(result,result+cnt);
    for (int i=0;i<cnt;i++){
         cout<<result[i]<<endl;
    }
     
    return 0;
}