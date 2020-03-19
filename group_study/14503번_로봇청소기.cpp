#include <iostream>
using namespace std;
int n,m,cnt;
int **input;
pair<int,int> direct[4]={{-1,0},{0,1},{1,0},{0,-1},};  //북 동 남 서 

int print(){
    cout<<"===================="<<endl;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>n>>m;
    
    input=new int*[n];
    for (int i=0;i<n;i++){
        input[i]=new int[m];
    }
    
    int startx, starty,d;
    cin>>startx>>starty>>d;
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>input[i][j];
        }
    }

    int x,y;
    x=startx;
    y=starty;
    cnt=0;
    while(1){
        cout<<"( "<<x<<" , "<<y<<" ) "<<d<<" cnt: "<<cnt<<endl;
        
        if(input[x+1][y]!=0 &&  input[x][y+1] !=0 && input[x-1][y]!=0 && input[x][y-1]!=0 && input[x][y]!=0 ) break;

        //제일 먼저 청소 체크 
        int nextx,nexty,nextd;
        input[x][y]=3;
        cnt++;
        

        print();
        input[x][y]=2;
        nextd=d;
        for (int i=0;i<4;i++){
            nextd=(nextd+3)%4;
            nextx=x+direct[nextd].first;
            nexty=y+direct[nextd].second;
            cout<<"for: ( "<<nextx<<" , "<<nexty<<" ) "<<nextd<<endl;
            
            if(nextx>0 && nextx<n-1 && nexty>0 && nexty<m-1 && input[nextx][nexty]==0){
                x=nextx;
                y=nexty;
                d=nextd;
                break;
            }
        }
        if(nextx>0 && nextx<n-1 && nexty>0 && nexty<m-1 && input[nextx][nexty]==0){
            continue;
        }
        //네방향 모두 청소가 되어 있거나 벽인 경우 . 바라보는 방향을 유지한채로 한칸 후진 2번으로 돌아감
        nextx=x+direct[(d+2)%4].first;
        nexty=y+direct[(d+2)%4].second;

        if(nextx>0 && nextx<m-1 && nexty>0 && nexty<n-1){
            cout<<"hougine"<<endl;
            x=nextx;
            y=nexty;
            d=nextd;
            continue;
        }
        cout<<"don't go anywhere"<<endl;
        break;
        

    }
    cout<<cnt;
        return 0;

}