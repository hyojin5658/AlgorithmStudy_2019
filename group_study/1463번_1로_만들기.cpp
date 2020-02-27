#include<iostream>
#include<algorithm>
using namespace std;
int d[1000001];



int main(){
    int num;
    cin>>num;
    int calc[3]={6,2,3};
    d[0]=0;
    d[1]=0;
    d[2]=1;
    for (int i=3;i<=num;i++){
        if(i%2!=0 and i%3!=0) d[i]=d[i-1]+1;
        else{   //i가 2의 배수이거나 3의 배수이면
            int min_res=1000000;
            for (int j=0;j<3;j++){
                // cout<<i<<":"<<j<<"/"<<i%calc[j]<<"/"<<d[i/calc[j]]+1<<endl;
                if(i%calc[j]==0){ // 해당 배수 이면,
                    // cout<<i<<":"<<j<<"/"<<min_res<<endl;
                    if(j==0){
                        min_res=min(min_res,d[i/calc[j]]+2);
                    }
                    else{
                        min_res=min(min_res,d[i/calc[j]]+1);
                    }
                }
            }
            min_res=min(d[i-1]+1,min_res);
            d[i]=min_res;
        }
        // cout<<"result"<<i<<":"<<d[i]<<endl;

    }
    cout<<d[num];
    return 0;
}