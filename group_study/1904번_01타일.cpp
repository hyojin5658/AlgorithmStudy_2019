#include<iostream>
using namespace std;
#define mod 15746

int main(void){
    long long  len;
    cin>>len;
    long long data[len+1];
    data[1]=1;
    data[2]=2;
    for (int i=3;i<=len;i++){
        data[i]=(data[i-1]+data[i-2])%mod;
    }

    cout<<data[len];
    return 0;
}