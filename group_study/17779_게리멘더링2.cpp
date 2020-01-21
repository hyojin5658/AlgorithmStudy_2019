//답은 나옴, 그러나 백준에서는 틀렸습니다. 
#include <iostream>
#include <vector>
#include <algorithm> // max 값 찾기 위함 
#include <string.h>

using namespace std;

typedef struct {
    int x;
    int y;

    int d1;
    int d2;
}dot;

int len;
int **data;
int **zonemap;
int *result;
vector<dot> combi;



void SetCombi(){
    //x, y 고정 하고, di d2 가능한 것을 벡터에 집어 넣기.
    for (int x=0;x<len;x++){
        for (int y=0;y<len;y++){
            // 가능한 d1 d2 구하기,
            for (int d1=1;d1<len;d1++){
                for (int d2=1;d2<len;d2++){
                    if ( x<x+d1+d2 and x+d1+d2<=(len-1) and 0<=y-d1 and y-d1<y and y+d2<=len-1){
                         combi.push_back({x,y,d1,d2});
                         //cout<<"set combi: ("<<x<<","<<y<<") "<<d1<<"/"<<d2<<endl;
                    }
                }
            }
        }
    }
}

// void print(){
//     for (int x=0;x<len;x++){
//         for (int y=0;y<len;y++){
//         cout<<zonemap[x][y]<<' ';
//         }
//         cout<<endl;
//     }
//      cout<<"----------------"<<endl;
// }
void dfs(int r,int c,int zonenum,int x,int y,int d1, int d2){
    //cout<<"dfs: x="<<r<<" y: "<<c<<" zonenum "<<zonenum<<endl;
    zonemap[r][c]=zonenum;
    dot points[4]={{0,1,0,0},{0,-1,0,0},{-1,0,0,0},{1,0,0,0}};
    for (int i=0;i<4;i++){
        int nextr=r + points[i].x;
        int nextc=c + points[i].y;
        //cout<<"for method: nextx="<<nextr<<" nexty: "<<nextc<<" zonenum "<<zonenum<<endl;
        if ( 0<= nextr and nextr<len and 0<=nextc and nextc<len){
            //cout<<"for method: nextx="<<nextr<<" nexty: "<<nextc<<" zonenum "<<zonenum<<endl;
            if (zonemap[nextr][nextc]==0  ){
                if (zonenum==1 and 0<=nextr and nextr<x+d1 and 0<=nextc and nextc<=y){
                    dfs(nextr,nextc, zonenum,x,y,d1,d2);
                }
                else if (zonenum==2 and  0<=nextr and nextr<=x+d2 and  y<nextc  and nextc<len ){
                    dfs(nextr,nextc, zonenum,x,y,d1,d2);
                }
                else if (zonenum==3 and x+d1<=nextr and nextr<len and 0<=nextc and nextc<y-d1+d2){
                    dfs(nextr,nextc, zonenum,x,y,d1,d2);
                } 
                else if (zonenum==4 and x+d2<nextr and nextr<len and  y-d1+d2<=nextc and nextc<len){
                    dfs(nextr,nextc, zonenum,x,y,d1,d2);
                }
            }
        }   
    }
}
    
int CalcCombi(){
    int min_result,comb_result;
    int max_people,min_people;
    int zone;
    int x,y,d1,d2;
    min_result=1000;

    dot position;
    //벡터에 있는 조합을 꺼내면서 계산.
    for (int i=0;i<combi.size();i++){
        memset(result,0,sizeof(int)*len);
        min_people=1000;
        max_people=0;
        
        for (int i=0;i<len;i++){
            memset(zonemap[i],0,sizeof(int)*len);
        }

        position=combi.at(i);
        x=position.x;
        y=position.y;
        d1=position.d1;
        d2=position.d2;
        
        // cout<<"Start combi: x="<<x<<" y: "<<y<<" d1: "<<d1<<" d2: "<<d2<<endl;
        //zonemap에 구역 표시 
        // zonemap의 같은 구역 계산(data를 참조)
        // zonemap[x][y]=5;
        // zonemap[x+d2+d1][y+d2-d1]=5;
        for (int i=0;i<=d1;i++){
             if ( 0<= x+i and x+i<len and
                  0<=y-i and y-i<len and 
                  0<=x+d2+d1-i and x+d2+d1-i<len and 
                  0<y+d2-d1+i and y+d2-d1+i<len){
                    //cout<<"Start combi: x="<<x+i<<" y: "<<y-i<<" d1: "<<x+d2+d1-i<<" d2: "<<y+d2-d1+i<<endl;
                    zonemap[x+i][y-i]=5;
                    zonemap[x+d2+d1-i][y+d2-d1+i]=5;
             }
        }
        for (int i=0;i<=d2;i++){
            if ( 0<= x+i and x+i<len and
                  0<=y+i and y+i<len and 
                  0<=x+d2+d1-i and x+d2+d1-i<len and 
                  0<y+d2-d1-i and y+d2-d1-i<len){
                    //cout<<"Start combi: x="<<x+i<<" y: "<<y-i<<" d1: "<<x+d2+d1-i<<" d2: "<<y+d2-d1+i<<endl;
                    zonemap[x+i][y+i]=5;
                    zonemap[x+d2+d1-i][y+d2-d1-i]=5;
                  }
        }
  
        vector<dot> points={{0,0,0,0},{0,len-1,0,0},{len-1,0,0,0},{len-1,len-1,0,0}};
        for(int r=0;r<4;r++){
           dfs(points.at(r).x,points.at(r).y,r+1,x,y,d1,d2);
        }
        for (int i=0;i<len;i++){
            for (int j=0;j<len;j++){
                int zone=zonemap[i][j];
                if (zone==0) zone=5;
                result[zone-1]+=data[i][j];
                
            }
        }
        //cout<<"----------------"<<endl;
        //print();
        for (int i=0;i<5;i++){
            max_people=max(max_people,result[i]);
            min_people=min(min_people,result[i]);
            // cout<<i<<"res"<<result[i]<<endl;
            // cout<<i<<"min"<<min_people<<endl;
            // cout<<i<<"max"<<max_people<<endl;
        }
        // cout<<"max-min"<<max_people-min_people<<endl;
        // cout<<"min_result"<<min_result<<endl;
        min_result=min(max_people-min_people, min_result);
        // cout<<"min_result2"<<max_people-min_people<<endl;
        
    } 

    
    return min_result;
}

int main(void){
    
    int x;

    //1. 입력 받기
    cin>>len;

    //초기화 
    data=new int*[len];
    for (int i=0;i<len;i++){
        data[i]=new int[len];
        memset(data[i],0,sizeof(int)*len);
    }
    zonemap=new int*[len];
    for (int i=0;i<len;i++){
        zonemap[i]=new int[len];
        memset(zonemap[i],0,sizeof(int)*len);
    }
   
       //데이터 입력 받기
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            cin>>data[i][j];
        }
    }
     result= new int[len];    
   
    //2. 조합 찾기
    SetCombi();
    //3. 하나씩 계산
    int min=CalcCombi();
    //4. 최솟값 출력
    cout<<min; 
    //메모리 해제 
    for (int i=0;i<len;i++){
        delete [] data[i];
        delete [] zonemap[i];
    }

    return 0;
}