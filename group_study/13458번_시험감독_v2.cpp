#include<iostream>
#include<string.h>

using namespace std;
long long  N,A,B,C;
long long  *room;

int calc_first_room(int i){
    long long  cnt=0;
    long long  tmp=room[i];
    tmp-=B;
    cnt++;
    // cout<<"##"<<tmp<<endl;
    if (tmp<=0) return cnt;
    else if(tmp%C==0) return cnt+(tmp/C);
    else return cnt+(int(tmp/C))+1;
}

int main(void){
    cin>>N;
    room=new long long [N];
    memset(room,0,sizeof(long long )*N);

    for (int i=0;i<N;i++){
        cin>>room[i];
    }

    cin>>B>>C;
    long long  result=0;
    for (int i=0;i<N;i++){
        long long  res=calc_first_room(i);
        result+=res;
    }
    
    
    cout<<result;
    return 0;
}