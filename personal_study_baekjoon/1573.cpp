//https://www.acmicpc.net/problem/2468 안전영역 문제
//메모리 초과로 실패함
#include <iostream>
#include <queue> 

#define endl '\n'
#define MAX 100

using namespace std;

int len;
int max_len=1;
int min_len=100;
int data_Ar[MAX][MAX],data_cp[MAX][MAX],len_Ar[MAX];

typedef struct{
    int x;
    int y;
}st;
queue<st> q;


void Input()
{
    //1. 개수 입력 받기 
    
    cin>>len;

    //데이터 입력 받기
    for (int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            cin>>data_Ar[i][j];
            //int data=data_Ar[i][j];
            if(data_Ar[i][j]>max_len) max_len=data_Ar[i][j];
            else if(data_Ar[i][j]<min_len) min_len=data_Ar[i][j];
            len_Ar[data_Ar[i][j]]=1;
        }
    }

}

void Copy_MAP(){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            data_cp[i][j] = data_Ar[i][j];
        }
    }
}

void bfs(int i,int j,int depth){

    q.push({i,j});
    while(!q.empty()){
        i=q.front().x;
        j=q.front().y;
        q.pop();
        data_cp[i][j]=-1;

        if(data_cp[i][j+1]>depth){
            q.push({i,j+1});
        }
        if (data_cp[i+1][j]>depth){
            q.push({i+1,j});
        }
        if(data_cp[i][j-1]>depth) {
            q.push({i,j-1});
        }
        if(data_cp[i-1][j]>depth){
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
    
    Input();
    Solve();

    return 0;
}