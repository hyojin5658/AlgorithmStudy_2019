//https://www.acmicpc.net/problem/2468 안전영역 문제
//메모리 초과로 실패함
#include <iostream>
#include <string.h>

#define endl '\n'
#define MAX 100

using namespace std;

int len = 0;
// int** data_Ar;
// int** data_cp;
int data_Ar[MAX][MAX];
int data_cp[MAX][MAX];

typedef struct{
    int x;
    int y;
}st;
st moveXY[4]={{0,1},{1,0},{0,-1},{-1,0}};

void Copy_MAP(int depth){
    for (int i = 0; i < len; i++){
        for (int j = 0; j < len; j++){
            if (data_Ar[i][j]> depth){
                data_cp[i][j] = data_Ar[i][j];
            }
            else{
                data_cp[i][j] =-1;
            }
        }
    }
}

void bfs(int i,int j,int depth){
    data_cp[i][j]=-1;
    for (int k=0;k<4;k++){
        int nexti=i+moveXY[k].x;
        int nextj=j+moveXY[k].y;

        if( 0<=nexti and nexti<len and 0<=nextj and nextj<len){
            if(data_cp[nexti][nextj]!=-1 and data_cp[nexti][nextj]>depth)
            {
                bfs(nexti,nextj,depth);
            }
        }
    }

}

void Solve() {
    int max_count=-1;
    int count;
    for (int k=0;k<MAX;k++){
        count=0;
        Copy_MAP(k);
        for (int i=0;i<len;i++){
            for (int j=0;j<len;j++){
                if (data_Ar[i][j]>k and data_cp[i][j]!=-1){
                    bfs(i,j,k);
                    count++;
                }
            }
        }
        max_count=max(max_count, count);
    } 
    cout<<max_count;
}

int main(void)
{
    cin>>len;

    // data_Ar= new int *[len];
    // for (int i=0;i<len;++i){
    //     data_Ar[i]=new int[len];
    //     memset(data_Ar[i], 0, sizeof(int)*len);
    // }

    // data_cp= new int *[len];
    // for (int i=0;i<len;++i){
    //     data_cp[i]=new int[len];
    //     memset(data_cp[i], 0, sizeof(int)*len);
    // }
    for (int i=0;i<len;i++){
        for(int j=0;j<len;j++){

            cin>>data_Ar[i][j];
        }
    }
    // for (int i=0;i<len;i++){
    //     for(int j=0;j<len;j++){

    //         data_cp[i][j]=0;
    //     }
    // }

    Solve();
    // for(int i = 0; i < len; ++i) { delete [] data_Ar[i]; } delete [] data_Ar;
    // for(int i = 0; i < len; ++i) { delete [] data_cp[i]; } delete [] data_cp;
    return 0;
}