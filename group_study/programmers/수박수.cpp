#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    string su[2]={"수","박"};
    for(int i=0;i<n;i++){
        answer+=su[i%2];    
    }
    cout<< answer<<endl;;
}

int main ( ){
    solution(4);
    return 0;

}