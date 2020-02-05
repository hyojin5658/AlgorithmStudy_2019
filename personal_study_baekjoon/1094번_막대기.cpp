#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main(void){
    int length;
    cin>>length;
    vector<int> bars;

    bars.push_back(64);

    while(1){
        int plus=0;
        int bar, min_bar=10000;
        int min_bar_index;

        for(int i=0;i<bars.size();i++){
            bar=bars.at(i);
            plus+=bar;
            if(min_bar>bar){
                min_bar=bar;
                min_bar_index=i;
            }
        }
        if (plus>length){
            bars.erase(bars.begin()+min_bar_index);
            if ((plus-int(min_bar/2))>=length){
                bars.push_back(int(min_bar/2));
            }
            else{
                bars.push_back(int(min_bar/2));
                bars.push_back(int(min_bar/2));
            }
        }
        else if(plus==length)
        {
            cout<<bars.size()<<endl;
            break;
            return 0;
        }
    }
    
    
    return 0;
}