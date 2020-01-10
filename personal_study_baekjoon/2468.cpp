//https://www.acmicpc.net/problem/2468 안전영역 문제
//메모리 초과로 실패함
#include <iostream>
#include <queue> 
#include<string.h>

#define endl '\n'
#define MAX 100

using namespace std;

int len;
int max_len=1;
int min_len=100;
int** data_Ar;
int** data_cp;
// int data_Ar[MAX][MAX];
// int data_cp[MAX][MAX];
int len_Ar[MAX];

typedef struct{
    int x;
    int y;
}st;
queue<st> q;

void Copy_MAP(){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            data_cp[i][j] = data_Ar[i][j];
        }
    }
}

void bfs(int i,int j,int depth){
    cout<<"bfs:"<<' '<<i<<' '<<j<<' '<<depth<<endl;
    q.push({i,j});
    while(!q.empty()){
        i=q.front().x;
        j=q.front().y;
        q.pop();
        data_cp[i][j]=-1;

        if( j<len and  data_cp[i][j+1]>depth){
            q.push({i,j+1});
        }
        if (i<len and data_cp[i+1][j]>depth){
            q.push({i+1,j});
        }
        if(j>0 and data_cp[i][j-1]>depth) {
            q.push({i,j-1});
        }
        if(i>0 and data_cp[i-1][j]>depth){
            q.push({i-1,j});
        }
    }
}

void Solve() {
    int max_count=0;
    int count;
    for (int k=min_len;k<max_len+1;k++){
        count=0;
        Copy_MAP();
        for (int i=0;i<len+1;i++){
            for (int j=0;j<len;j++){
                if (data_cp[i][j]>k){
                    count++;
                    bfs(i,j,k);
                }
                else{
                    data_cp[i][j]=-1;
                }
            }
        }
        len_Ar[k]=count;
        if(count>max_count) max_count=count;
    } 
    cout<<max_count<<endl;
}

int main(void)
{
    //이걸 입력하면 입출력 속도 빨라짐. 대신 c api 사용하지 말기
    //endl 대신 '\n' 사용하기 
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    //1. 개수 입력 받기 
    cin>>len;

    data_Ar= new int *[MAX];
    for (int i=0;i<MAX;++i){
        data_Ar[i]=new int[MAX];
        //memset(data_Ar[i], 0, sizeof(int)*len);
    }

    data_cp= new int *[MAX];
    for (int i=0;i<MAX;++i){
        data_cp[i]=new int[MAX];
        //memset(data_cp[i], 0, sizeof(int)*len);
    }

    //데이터 입력 받기
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            cin>>data_Ar[i][j];
            //int data=data_Ar[i][j];
            data_Ar[i][j]>max_len? max_len=data_Ar[i][j]: max_len;
            data_Ar[i][j]<min_len? min_len=data_Ar[i][j]: min_len;
            len_Ar[data_Ar[i][j]]=1;
        }
    }

    Solve();

    return 0;
}