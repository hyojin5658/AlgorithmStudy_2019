#include <iostream>
#include <vector>
using namespace std;

typedef struct{
    int start;
    int end;
}node;

vector<node> Data;
int nodeNum; //컴퓨터 수 
int len;
bool *check; //모두 돌았는지 체크

void Find(int no){

    check[no-1]=true;

    int nextNo;

    //데이터를 돌아다니며 연결된 노드 탐색
    for (int i=0;i<Data.size();i++){
        if(Data.at(i).start==no and check[(Data.at(i).end)-1]==false){
            Find(Data.at(i).end);
        }
            
    }
}

int main(void){
    //노드 개수 및 데이터 입력 받음 
    cin>>nodeNum;
    check=new bool[nodeNum];
    int len;
    cin>>len;

    for (int i=0;i<len;i++){
        int x,y;
        cin>>x>>y;
        Data.push_back({x,y});
        Data.push_back({y,x});
    }
    //check 배열 초기화 
    for (int i=0;i<nodeNum;i++){
        check[i]=false;
    }
    //데이터 출력 함수 
    // cout<<"Data size:"<< Data.size()<<endl;
    // for (int i=0;i<Data.size();i++){
    //     cout <<" Input: "<< Data.at(i).start <<"/"<<Data.at(i).end<<" check: "<<check[(Data.at(i).end)-1]<<endl;    
    // }
    // cout<<"finish cout input"<<endl;

    //노드 1부터 시작 
    Find(1);
    int cnt=0; 
    for(int i=0;i<nodeNum;i++){
        if (check[i]==true){
            cnt++;
        }
    }
    cout<<cnt-1;
    return 0;

}
