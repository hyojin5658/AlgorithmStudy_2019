//1월 9일 까지 숙제 
//연구소 과제 
#include <iostream>
#include <stack>
#include <vector>

#define endl "\n"
#define MAX 8
using namespace std;

int row,col;
int DataArray[MAX][MAX], Data_cp[MAX][MAX];
int check[MAX][MAX];
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
vector<int> wall_list;
vector<points>wall_comb;


void Input()
{
    int cnt=0;
    cin>>row>>col;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>DataArray[i][j];
            if(DataArray[i][j]==0) {wall_list.push_back(cnt);}
            cnt++;
            //cout<<cnt<<endl;
            //cout<<"wall_list size:"<<wall_list.size()<<endl;
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
    //cout<<"finish copy data copy"<<endl;
}
void checkWall()// 찾을 수 있는 벽의 조합 모두 찾아서 저장 
{
    points data;
    for (int i=0;i<wall_list.size();i++)
    {
        for (int j=i+1;j<wall_list.size();j++)
        {
            for(int k=j+1;k<wall_list.size();k++)
            {
                data.point1.i=int(wall_list.at(i)/col);
                data.point1.j=wall_list.at(i)%col;
                data.point2.i=int(wall_list.at(j)/col);
                data.point2.j=wall_list.at(j)%col;
                data.point3.i=int(wall_list.at(k)/col);
                data.point3.j=wall_list.at(k)%col;

                wall_comb.push_back(data);
                //cout<<"check wall"<<" / "<<i<<" / "<<j<<" / "<<k<<endl;
                //cout<<"check wall"<<" / "<<data.point1.i<<' '<<data.point1.j<<" / "<<data.point2.i<<' '<<data.point2.j<<" / "<<data.point3.i<<' '<<data.point3.j<<endl;
            }
        }
    }
    

}

void MakeWall( points point)
{
    // cout<<point.point1.i<<" / "<<point.point1.j <<endl;
    // cout<<point.point2.i<<" / "<<point.point2.j <<endl;
    // cout<<point.point3.i<<" / "<<point.point3.j <<endl;
    Data_cp[point.point1.i][point.point1.j]=1;
    Data_cp[point.point2.i][point.point2.j]=1;
    Data_cp[point.point3.i][point.point3.j]=1;
}


int DFS(int i,int j)
{
    //cout<<"dfs ("<<i<<","<<j<<")"<<endl;
    //일단 처리,
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

    while(!s.empty())// 스택이 비어있지 않으면,! 
    {
        i=s.top().i;
        j=s.top().j;
    //    cout<<"stack pop ("<<i<<","<<j<<")"<<endl;
        s.pop();
        return DFS(i,j);
    }
    return 0;
}

void Emergency()
{
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(Data_cp[i][j]==2)//바이러스 발견 
            {
                //cout<<"emergency:"<<i<<","<<j<<endl;
                DFS(i,j);
            }
        }
    }
    //cout<<"finish emergency"<<endl;
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
    /*
    1. 벽 세우기// 이걸 어떻게 구현하지 ?ㅎㅎㅎㅎㅎ
    2. 바이러스 퍼트리기 -> dfs로 구현 
    3. 안전한 공간 체크 //모든 데이터 0인지 체크 
    
    1~3번 과정을 모든 과정 모두 반복 
    */
   points data;

   Copy();
   checkWall();
    for (int i=0;i<wall_comb.size();i++)//모든 경우의 수 체크
    {
        data=wall_comb.at(i);
        Copy();
        MakeWall(data);
        Emergency();
        int safe=CheckSafe(); // 안전한 공간 개수 반환
        if (safe>max_safe){ // 최대값 계산 
            max_safe=safe;
        }
        //cout<<"finish checksafe: "<<safe<<" / "<<data.point1.i<<" "<<data.point1.j <<" / "<<data.point2.i<<" "<<data.point2.j<<" / " <<data.point3.i<<" "<<data.point3.j <<" / " <<i<<endl;
    }
    wall_comb.clear();
    return max_safe;
}


int main()
{
    Input();
    int result=Solution();
    cout<<result;
    
    return 0;
}