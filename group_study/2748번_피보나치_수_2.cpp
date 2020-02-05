<<<<<<< HEAD

#include<iostream>

using namespace std;
long long  data[90];
long long fibo(int n){
    long long sum=0;
         data[0]=0;
         data[1]=1;
    for (int i=2;i<=n;i++){
        data[i]=data[i-1]+ data[i-2];
    }
    return data[n];
}

int main(void){
    int len;
    cin>>len;

    long long  res=fibo(len);

    cout<<res;
    return 0;
=======

#include<iostream>

using namespace std;
long long  data[90];
long long fibo(int n){
    long long sum=0;
         data[0]=0;
         data[1]=1;
    for (int i=2;i<=n;i++){
        data[i]=data[i-1]+ data[i-2];
    }
    return data[n];
}

int main(void){
    int len;
    cin>>len;

    long long  res=fibo(len);

    cout<<res;
    return 0;
>>>>>>> 286431669617b03630ce417a821a5c7ad848d184
}