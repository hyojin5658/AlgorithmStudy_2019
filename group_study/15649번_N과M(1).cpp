#include<iostream>

using namespace std;
int arr[9];
bool visited[9];

int N,M;
int make(int cnt){
    if(cnt==M){
        for (int i=0;i<M;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    for (int i=1;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[cnt]=i;
            make(cnt+1);
            visited[i]=false;
        }
    }
    return 0;
}

int main(void){
    cin>>N>>M;
    
    make(0);
    return 0;
}