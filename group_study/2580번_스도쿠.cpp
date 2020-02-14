#include <iostream>
#define len 9

using namespace std;
int data[len][len];
pair<int,int> square_info[9]={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};

bool search_square(int zone){
    int startx= square_info[zone].first;
    int starty=square_info[zone].second;
    for (int i=startx;i<startx_3;i++){
         for (int i=starty;i<starty+3;i++){
             //하나만 이ㅣㅆ으면 채우기
         }
    }
}


int main(){
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            cin>>data[i][j];
        }
    }

    for (int i=0;i<len;i++){
        bool result;
        result=search_square(i);
    }



    return 0;
}