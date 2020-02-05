#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> results;

#define MAX 500
 int len;
int data[MAX][MAX];

int calc(int x,int y,int result){
    cout<<"calc : "<<x<<y<<result<<endl;
    if (x+1>len){
        result=result+data[x+1][y];
        results.push_back(result);
        return 0;
    }
    result=result+data[x+1][y];
    
    for (int i=0;i<2;i++){
        calc(x+1,y+i,result);
    }

    return 0;

}

int main(void){
   
    cin>>len;
    
    for (int i=0;i<len;i++){
        for (int j=0;j<=i;j++){
            cin>>data[i][j];
        } 
    }

    calc(0,0,data[0][0]);

    int max_res=0; 
    for(int i=0;i<results.size();i++){
        max_res=max(max_res,results.at(i));
    }
    cout<<max_res;

}