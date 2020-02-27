#include <iostream>
#include <string.h>
#define len 9

using namespace std;
int sdoku[len][len];
pair<int,int> square_info[9]={{0,0},{0,3},{0,6},{3,0},{3,3},{3,6},{6,0},{6,3},{6,6}};
bool number[10];
struct pos{
    int x;
    int y;
    int num;
};

int print_sudoku(){
    cout<<"-----"<<endl;
      for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            cout<<sdoku[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"-----"<<endl;
    return 0;
}

bool search_square(int zone){
    int cnt=0;
    pos tmp_pos;
    int startx= square_info[zone].first;
    int starty=square_info[zone].second;
    memset(number,false,sizeof(10));
    for (int i=startx;i<startx+3;i++){
         for (int j=starty;j<starty+3;j++){        
            int tmp=sdoku[i][j];
            number[tmp]=true;
            if (tmp==0){
                cnt++;
                tmp_pos={i,j,tmp};
            }
            
         }
    }
    //빈칸이 1개 일 경우 
    if (cnt==1){
        int last_nine;
        for (int i=1;i<10;i++){
            if(number[i]==false){
                last_nine=i;
                break;
            }
        }
        cout<<"switch-"<<zone<<" zone, ("<<tmp_pos.x<<" , "<<tmp_pos.y<<") to "<<last_nine<<endl;
        sdoku[tmp_pos.x][tmp_pos.y]=last_nine;
        return true;
    }
    //빈칸이 2개 이상일 경우 
    else if(cnt>1){
    }
    //빈칸이 없을 경우
    else{
    }
    return true;
}

bool search_rows(){
   
    pos tmp_pos;
    for (int i=0;i<len;i++){
        int cnt=0;
        memset(number,false,sizeof(10));
         for (int j=0;j<len;j++){
            int tmp=sdoku[j][i];
            number[tmp]=true;
            if (tmp==0){
                cnt++;
                tmp_pos={i,j,tmp};
            }
        }
        if (cnt==1){
            int last_nine;
            for (int i=1;i<10;i++){
                if(number[i]==false){
                    last_nine=i;
                    break;
                }
            }
            cout<<"switch- row, ("<<tmp_pos.x<<" , "<<tmp_pos.y<<") to "<<last_nine<<endl;
            sdoku[tmp_pos.x][tmp_pos.y]=last_nine;
        }
        //빈칸이 2개 이상일 경우 
        else if(cnt>1){
        }
        //빈칸이 없을 경우
        else{
        }
    }
    
    return true;
}

bool search_cols(){
    pos tmp_pos;
    for (int i=0;i<len;i++){
        int cnt=0;
        memset(number,false,sizeof(10));
         for (int j=0;j<len;j++){
            int tmp=sdoku[i][j];
            number[tmp]=true;
            if (tmp==0){
                cnt++;
                tmp_pos={i,j,tmp};
            }
            
         }
         //빈칸이 1개 일 경우 
        if (cnt==1){
            int last_nine;
            for (int i=1;i<10;i++){
                if(number[i]==false){
                    last_nine=i;
                    break;
                }
            }
            cout<<"switch-"<<" zone, ("<<tmp_pos.x<<" , "<<tmp_pos.y<<") to "<<last_nine<<endl;
            sdoku[tmp_pos.x][tmp_pos.y]=last_nine;
        }
    }
    
    return true;
}


int main(){
    for (int i=0;i<len;i++){
        for (int j=0;j<len;j++){
            cin>>sdoku[i][j];
        }
    }

    print_sudoku();

    for (int i=0;i<len;i++){
        bool result;
        result=search_square(i);
    }
    cout<<"1.<finish zonemap>"<<endl;
    print_sudoku();
    search_rows();
    cout<<"2. finish rows"<<endl;
    print_sudoku();
    search_cols();
    cout<<"3. finish cols"<<endl;
    print_sudoku();


    return 0;
}