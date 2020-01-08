//1월 9일 까지 숙제 
//연구소 과제 
#include <iostream>
#include <stack>
#include <vector>
#include <time.h>

#define endl "\n"
#define MAX 8
using namespace std;

int row,col;
int DataArray[MAX][MAX], Data_cp[MAX][MAX];
int max_safe=0;

typedef struct {
    int i;
    int j;
}point;

typedef struct {
    point point1;
    point point2;
    point point3;
}points;

stack<point> s;
vector<point> wall_list;
vector<point> virus;
vector<points> wall_comb;


void Input()
{
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>DataArray[i][j];
            if(DataArray[i][j]==0) {wall_list.push_back({i,j});}
            if(DataArray[i][j]==2) {virus.push_back({i,j});}
        }
    }
}
void Copy()
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            Data_cp[i][j]=DataArray[i][j];
        }
    }
}
void checkWall()
{
    for (int i=0;i<wall_list.size();i++){
        for (int j=i+1;j<wall_list.size();j++){
            for(int k=j+1;k<wall_list.size();k++){
                wall_comb.push_back({{wall_list.at(i)},{wall_list.at(j)},{wall_list.at(k)}});
            }
        }
    }
}

void MakeWall( points point)
{
    Data_cp[point.point1.i][point.point1.j]=1;
    Data_cp[point.point2.i][point.point2.j]=1;
    Data_cp[point.point3.i][point.point3.j]=1;
}

int DFS(int i,int j)
{
    Data_cp[i][j]=2;
    if (Data_cp[i][j+1]==0 and j<col){
        s.push({i,j+1});
    }
    if (Data_cp[i+1][j]==0 and i<row){
        s.push({i+1,j});
    }
    if (Data_cp[i][j-1]==0 and j!=0){
        s.push({i,j-1});
    }
    if (Data_cp[i-1][j]==0 and i!=0){
        s.push({i-1,j});
    }

    while(!s.empty())
    {
        point data;
        data=s.top();
        s.pop();
        return DFS(data.i,data.j);
    }
    return 0;
}

void Emergency()
{
    for (int i=0;i<virus.size();i++){
        DFS(virus.at(i).i,virus.at(i).j);
    }
}

int CheckSafe()
{
    int count=0;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (Data_cp[i][j]==0) count++;
        }
    }
    return count;
}

int Solution(){
   points data;

   Copy();
   checkWall();
    for (int i=0;i<wall_comb.size();i++)
    {
        data=wall_comb.at(i);
        Copy();
        MakeWall(data);
        Emergency();
        int safe=CheckSafe(); 
        if (safe>max_safe){ 
            max_safe=safe;
        }
    }
    wall_comb.clear();
    return max_safe;
}

int main()
{
    clock_t now=clock();
    Input();
    int result=Solution();
    clock_t end=clock();
    cout<<result<<endl;
    printf("Time : %lf\n",(double)(end - now)/CLOCKS_PER_SEC);
    
    return 0;
}