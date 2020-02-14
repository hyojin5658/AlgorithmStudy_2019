#include <iostream>
#include <stack>

using namespace std;

stack<int> *s;
int *stackSize;
int len;
int main_bar;
struct typedef{
    int bar;
    int floor;
}locInfo;

locInfo findNum(int num){
    
    return {bar, floor};
}


int main(){
    cin>>len;
    s=new stack<int>[len];
    stackSize=new int[len];
    
    for (int i=0;i<3;i++){
        cin>>stackSize[i];
    }
    for (int i=0;i<3;i++){
        for (int j=0;j<stackSize[i];j++){
            int tmp;
            cin>>tmp;
            s[i].push(tmp);
        }
    }

    cout<<"success!"<<endl;

    for (int i=0;i<3;i++){
        cout<<"size:"<<s[i].size()<<endl;
    }
    
    locInfo tmp;
    tmp=findNum(); // 찾고자하는 숫자가 어디에 있는지 파악, 어디에다가 해야 하는지 파악 하기 
    
    move()


    return 0;
}