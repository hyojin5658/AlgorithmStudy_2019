#include <iostream>
#include <string.h>
#include <queue>

using namespace std;
int len, height;
int **data;
struct point {
    int x;
    int y;
};
queue<point> que;
int cnt=1;
int nextt[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int max_res=0;

int dfs(){
    while(que.size()!=0){
        //cout<<"dfs front:"<<" / "<<que.front().x<<" / "<<que.front().y<<" / "<<"/data:"<<data[que.front().x][que.front().y]<<" / " <<cnt<<" / "<<que.size()<<endl;
        point tmp= que.front();
        que.pop();
        for (int j=0;j<4;j++){
            int nextx=tmp.x+nextt[j][0];
            int nexty=tmp.y+nextt[j][1];
            //cout<<"dfs"<<" / "<<nextx<<" / "<<nexty<<" / ";
            if(0<=nextx and nextx<height and 0<=nexty and nexty<len and data[nextx][nexty]==0){
                //cout<<"----------->queue push";
                data[nextx][nexty]=data[tmp.x][tmp.y]+1;
                max_res=max(max_res,data[nextx][nexty]);
                que.push({nextx,nexty});
            }
           // cout<<endl;
        }
    }
}


int main(){
    cin>>len>>height;

    data=new int*[len];
    for (int i=0;i<height;i++){
        data[i]=new int[len];
        memset(data[i],0,sizeof(int)*len);
    }

    for (int i=0;i<height;i++){
        for (int j=0;j<len;j++){
            cin>>data[i][j];
        }
    }

    for (int i=0;i<height;i++){
        for (int j=0;j<len;j++){
            if (data[i][j]==1){
                que.push({i,j});
            }
        }
    }
    dfs();
    int max_res=0;
        for (int i=0;i<height;i++){
            for (int j=0;j<len;j++){
                if (data[i][j]==0){
                    cout<<"-1";return 0;
                }
                // else{
                //     max_res=max(max_res,data[i][j]);
                // }
            }
        }
        cout<<max_res-1;

    return 0;

}