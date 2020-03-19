#include<iostream>
#include<vector>

using namespace std;

int N;
int S[20][20];
bool *check;
bool *number;
vector<int> startv;
vector<int> linkv;
int calc(){
    int res_start=0, res_link=0;
    vector<pair<int,int>> combi;
    for(int i=0;i<startv.size();i++){
        for (int j=0;j<startv.size();j++){
            if(i!=j){
                combi.push_back({startv.at(i),startv.at(j)});
            }
        }
    }
    //계산
    for (int i=0;i<combi.size();i++){
        int x = combi.begin().second;


    }

    for(int i=0;i<linkv.size();i++){
        for (int j=0;j<linkv.size();j++){
            if(i!=j){
                combi.push_back({linkv.at(i),linkv.at(j)});
            }
        }
    }

}

int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin>>S[i][j];
        }
    }
    
    check=new bool[N];
    number=new bool[N/2];
    memset(number,0,sizeof(int)*N);
    memset(check,false,sizeof(bool)*(N/2));
    
    int i=0;
    while(i<=N/2){
        if(number[i+1]<N){
            startv.push_back(number[i]);
            check[number[i]]=true;
        }
        else{
            number[i]=number[i]+1;
            startv.push_back(number[i]);
            check[number[i]]=true;
        }
        i++;
    }
    for (int i=0;i<N;i++){
        if(!check) linkv.push_back(i);
    }

    calc();



}