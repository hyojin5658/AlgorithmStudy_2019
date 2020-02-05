#include <iostream>
#include<string.h>
using namespace std;
int len;
int dp[41];

int calc(int n){
    if (n<=0){
        dp[0]=0;
        return 0;
    }else if( n==1){
        dp[1]=1;
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    else{
        return dp[n]=calc(n-1)+ calc(n-2);
    }

}

int main(void){
   
    cin>>len;
    
    int data[len];
    for (int i=0;i<len;i++) cin>>data[i];
    memset(dp,0,sizeof(int)*41);

    for (int i=0;i<len;i++){
        int num=data[i];
        if (num==0) cout<<"1 0"<<endl;
        else if (num==1) cout<<"0 1"<<endl;
        else {
            calc(num);
            cout<<dp[num-1]<<' '<<dp[num]<<endl;
        }
    }
    return 0;
}