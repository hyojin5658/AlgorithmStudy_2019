#include<iostream>

using namespace std;
int arr[9];
bool visited[9];

int N,M;
int curr_index,previous_index, prev_number;
// int print(){
//     cout<<"----start--------"<<endl;
//     for (int i=0;i<=M;i++){
//         cout<< visited[i]<<" ";
//     }
//     cout<<endl;
//     for (int i=0;i<=M;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     cout<<"-------end--------"<<endl;
// }
int make(int cnt,int min){
    if(cnt==M){
        for (int i=0;i<M;i++){
            cout<<arr[i]<<" ";
            
        }
        cout<<endl;
        // print();
        return 0;
    }
    for (int i=min;i<=N;i++){
        if(!visited[i]){
            visited[i]=true;
            arr[cnt]=i;
            // print();
            make(cnt+1,i+1);
            visited[i]=false;
            
        }
        
    }
    return 0;
    
}

int main(void){
    cin>>N>>M;
    
    make(0,1);
    return 0;
}