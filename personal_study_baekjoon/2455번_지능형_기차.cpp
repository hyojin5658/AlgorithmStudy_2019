#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int a,b;
    int cnt=0;
    int max_result=0;
    cin>>a>>b;
    while(b!=0){
        cnt-=a;
        cnt+=b;
        max_result=max(max_result,cnt);

        cin>>a>>b;
        //cout<<max_result<<endl;;
    }
    cout<<max_result;
    return 0;
}