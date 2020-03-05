#include<iostream>
#include<string.h>

using namespace std;
int N,A,B,C;
long long  *room;
long long  *result;

int calc_first_room(){
    long long  cnt=0;
    long long  tmp=room[0];
    tmp-=B;
    cnt++;
    while(tmp>0){
        tmp-=C;
        cnt++;
    }
    result[0]=cnt;
    return cnt;
}
int calc_another(int i){
    if (room[i]==room[i-1]){
        result[i]=result[i-1];
        return result[i];
    }
    else{
        long long  tmp;
        if((room[i]-B)%C==0) {
            result[i]=1+((room[i]-B)/C);
            return result[i];
        }
        else if(room[i]>room[i-1]) {
            tmp=room[i]-B-(C*(result[i-1]-1));
            long long  cnt=0;
            if (tmp<0) cnt=0;
            else if(tmp<C) cnt=1;
            else if(tmp%C==0) cnt=tmp/C;
            else{
                cnt=int(tmp/C)+1;
            }   
            result[i]=result[i-1]+cnt;
        }
        else if(room[i]<room[i-1]){
            tmp=-1*(room[i]-B-(C*(result[i-1]-1)));
            long long cnt=0;
            if(tmp<C) cnt=0;
            else if(tmp%C==0) cnt=tmp/C;
            else{
                cnt=int(tmp/C)+1;
            }   
            result[i]=result[i-1]-cnt;
        } 
        return result[i];
    }
    
}

int main(void){
    cin>>N;
    room=new long long [N];
    result=new long long [N];
    memset(room,0,sizeof(long long )*N);
    memset(result,0,sizeof(long long)*N);

    for (int i=0;i<N;i++){
        cin>>room[i];
    }

    cin>>B>>C;
    calc_first_room();
    
    for (int i=1;i<N;i++){
        calc_another(i);
    }
    
    long long  res=0;
    for (int i=0;i<N;i++){
       res+=result[i];
    }
    cout<<res;
    return 0;
}