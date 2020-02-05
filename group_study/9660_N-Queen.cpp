#include <iostream>
#include <string.h>

using namespace std;
int len;
int **array;
int *result;
int row_cnt;

bool check(int x,int y){
//    cout<<"check: X: "<<x<<" y: "<<y<<endl; //true 이면 아무것도 겹치는게 없는 것 , false 이면 겹치는게 있는 것
    if (0<=x and x<len and 0<=y and y<len){
        for (int i=0;i<x;i++){
            int j=result[i];
            for (int k=0;k<len;k++){
                //cout<<"row: X: "<<x<<" y: "<<y<<" i: "<<i<<"  j: "<<j<<" k: "<<k<<endl;
                if((i==x and k==y)or (k==x and j==y) or x-y==i-j or x+y==i+j) return false;
            }
        }
        return true;
    }
}
int row(int x, int y){
    //cout<<"row: X: "<<x<<" y: "<<y<<" "<<len-1<<endl;
    if (x>=len-1) 
    {
        //cout<<"Return!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"<<row_cnt<<endl;
        return row_cnt;
    }

    for (int i=0;i<len;i++){
        bool ck=check(x+1,i);
       //cout<<"row_for: X: "<<x+1<<" i: "<<i<<" result:"<<ck<<endl;
        if (ck==true){
            result[x+1]=i;
            //cout<<"row_for: X: "<<x+1<<" i: "<<i<<" result:"<<ck<<endl;
            if (x+1==len-1){
                //cout<<"row_count!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!: X: "<<x+1<<" i: "<<i<<endl;
                 row_cnt++;
            }
//            cout<<"new row"<<endl;
            row(x+1,0);
        } 
    } 
//    cout<<"finish row method"<<endl;
    return row_cnt;
}


int main(void){
    //int len;
    cin>>len;

    result=new int[len];
    memset(result,-1,sizeof(int)*len);
    array=new int*[len];
    for (int i=0;i<len;i++){
        array[i]=new int[len];
        memset(array[i],0,sizeof(int)*len);
    }
    int cnt=0;
    //첫번째줄 
    for (int i=0;i<len;i++){
        //memset(result,-1,sizeof(int)*len);
        result[0]=i;
        //cout<<"main: "<< i <<endl;
        row_cnt=0;
        int row_result=row(0,i);
        cout<<"main: "<< i <<"result: "<<row_result<<endl;         
        if (row_result>0)cnt=cnt+row_result;
        result[0]=0;
    }
    cout<<cnt;
    

}