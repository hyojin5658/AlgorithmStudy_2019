#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;
int N,K ;// n은 개수, k는 최대 무게 
// pair<int,int> *stuff;
int min_res;
int *result;
int calc(int weight){
    // cout<<"calc!!"<<weight <<endl;
    if (weight<min_res) return 0;
    if (result[weight]>0){
        // cout<<"already exists"<< result[weight]<<endl;
        return result[weight]; //이미 지정한 값이 있으면 그 값을 return 
    } 
    
    int max_res=0;
    for (int i=1;i<int(weight/2)+1;i++){
        int first,second;
        if (i<min_res) first=0;
        else {
            if(result[i]>0) first=result[i];
            else first=calc(i);
        }

        if (weight-i<min_res) second=0;
        else {
            if(result[weight-i]>0) second=result[weight-i];
            else second=calc(weight-i);
        }
        
        int result_res=first+second;
        max_res=max(max_res,result_res);
    }
    result[weight]=max_res;
    // cout<<"Data is New! num:"<<weight<<", result: "<<max_res<<endl;
    return max_res;
}


int main(){
    cin>>N>>K;
    result= new int[K+1];
    // stuff= new pair<int,int>[N];
    memset(result,0,sizeof(int)*(K+1));
    for (int i=0;i<N;i++){
        int W,V;
        cin>>W>>V;
        min_res=min(min_res,W);
        // stuff[i]={W,V};
        result[W]=V;
    }
    // sort(stuff,stuff+N);

    cout<<calc(K);

    return 0;
}