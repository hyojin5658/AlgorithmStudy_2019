#include <iostream>
#include <string.h>
#include <queue>

using namespace std;

int m, n;// m이 가로로 몇개 있는지, n이 세로로 몇개 있는 지 
int **data;
struct point {
    int x;
    int y;
};
queue<point> que;
int nextt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int max_res=1;

void dfs(){
    //큐가 빌 때 까지 반복 
    while(!que.empty()){
        //큐의 가장 첫번째 요소 꺼내옴 
        point tmp=que.front();
        que.pop();
        //동서남북 검사 
        for (int j=0;j<4;j++){
            int nextx=tmp.x+nextt[j][0];
            int nexty=tmp.y+nextt[j][1];
            // 좌표가 배열 보다 큰지 검사 
            if (nextx<0 || nexty<0 || nextx>=n || nexty>=m)continue;
            //아직 안 들렀는지 검사 
            if (data[nextx][nexty]==0){
                //이전 좌표의 +1 한 값 데이터로 넣어줌 
                data[nextx][nexty]=data[tmp.x][tmp.y]+1;
                //최대 값 구하기 
                max_res=max(max_res,data[nextx][nexty]);
                //큐에 삽입 
                que.push({nextx,nexty});
            }
            
        }
    }
}


int main(){
    //세로, 가로 입력 
    cin>>m>>n;

    //동적 배열 초기화 
    data=new int*[n];
    for(int i=0;i<n;i++){
        data[i]=new int[m];
        memset(data[i],0,sizeof(int)*m);
    }

    //배열 입력 받음 
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>data[i][j];
        }
    }

    //토마토가 있는 위치 찾기 -> queue에 집어 넣음 
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (data[i][j]==1){
                que.push({i,j});
            }
        }
    }
    //토마토 전염 시작 
    dfs();
    
    //안익은 토마토가 있는지 확인
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if (data[i][j]==0){
                cout<<"-1";
                return 0;
            }
        }
    }
    cout<<max_res-1;

    return 0;

}