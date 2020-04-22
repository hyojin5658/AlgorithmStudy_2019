#include <string>
#include <vector>


using namespace std;

vector<int> solution(vector<int> answers) {
    int persons[3][10]={{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    int length[3]={5,8,10};
    int cntNo[3]={0,0,0};
    vector<int> answer;

    for(int j=0;j<3;j++){
        int cnt=0;
        for(int i=0;i<answers.size();i++){
            int index=i;
            if(index>=length[j]){
                index=(index+1)%length[j];
            }
            int one_answer=persons[j][index];
            if(one_answer==answers[index]){
                cnt++;
            }
        }
        cntNo[j]=cnt;
    }
    int max=-1;
    for(int i=0;i<3;i++){
        if(max<cntNo[i]){
            answer.clear();
            answer.push_back(i+1);
            max=cntNo[i];
        }
        else if(max==cntNo[i]){
            answer.push_back(i+1);            
        }
    }
    
    
    return answer;
}
