#include<iostream>
#include<string.h>
#include<vector>

using namespace std;
struct point{
    int pos;//위치 
    int dir;//남극인지 북극인지 
};
int direction[4];
vector<point> v[4];
vector<point> commands;//pos는 톱니 번호, dir는 방향 표시 
int len;

int v_move(){
    for(int i=0;i<4;i++){
        if(direction[i]==1){//시계방향
            point tmp=v[i].at(7);
            v[i].erase(v[i].begin()+7);
            v[i].insert(v[i].begin(),tmp);
        }
        else if (direction[i]==-1) {//반시계 방향
            point tmp=v[i].at(0);
            v[i].erase(v[i].begin());
            v[i].push_back(tmp);
        }   
    }
    return 0;
}
int print_vector(){
    cout<<"--------vector---------"<<endl;
    for (int i=0;i<4;i++){
        for (int j=0;j<8;j++){
            cout<<v[i].at(j).dir<<" ";
        }
        cout<<endl;
    }
    cout<<"--------------"<<endl;
}
int print_direction(){
    cout<<"--------direction---------"<<endl;
    for (int i=0;i<4;i++){
        cout<<direction[i]<<" ";
    }
    cout<<endl;
    cout<<"--------------"<<endl;
}

int move(int num, int direct){
    int tmp=num;
    // cout<<"into the move"<<num<<"/"<<direct<<endl;
    direction[num]=direct;
    while(num<3){//오른쪽을 체크하기 위함 
        if(v[num].at(2).dir!=v[num+1].at(6).dir){
            direction[num+1]=direction[num]*(-1);
            num++;
            // cout<<"right"<<num<<endl;
        } 
        else{break;}
    }
    num=tmp;
    while(num>0){//왼쪽을 체크하기 위함 
         if(v[num].at(6).dir!=v[num-1].at(2).dir){
              direction[num-1]=direction[num]*(-1);
              num--;
            //   cout<<"left"<<num<<endl;
         }
         else{break;}
         
    }
    // print_direction();
    v_move();
    // print_vector();
    return 0;
}

int main(){
    for(int i=0;i<4;i++){
        string str;
        cin>>str;
        for (int j=0;j<8;j++){
            v[i].push_back({j,stoi(str.substr(j,1))});
        }
    }
    cin>>len;
    for (int i=0;i<len;i++){
        int num, dir;
        cin>>num>>dir;
        commands.push_back({num-1,dir});
    }
    // cout<<"finish inputs"<<endl;
    
    for (int i=0;i<len;i++){
        point tmp=commands.at(i);
        memset(direction,0,sizeof(int)*4);
        move(tmp.pos,tmp.dir);
    }

    //점수 계산 
    int points=0;
    for(int i=0;i<4;i++){
        if(i==0 and v[i].at(0).dir==1) points+=1;
        else if(i==1 and v[i].at(0).dir==1) points+=2;
        else if(i==2 and v[i].at(0).dir==1) points+=4;
        else if(i==3 and v[i].at(0).dir==1) points+=8;
    }
    cout<<points;
    return 0;

}