/*
   一个非常普通的深度搜索，这个题讲道理应该做出来的，但是发现好像忽然脑子就不转动了。
   或者说有了一个想法以后就僵死了

*/




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        buildAnswer(result,n);
        return result;
    }
    void buildAnswer(vector<int> &result,int max){
        int value = 0 ;
        if(result.size() == 0){
            value = 0;
        }
        else{
            value = result.back();
        }
        for(int i = 0 ; i <= 9 ;i ++){
            if(value == 0 && i == 0){
                continue;
            }
            int addValue = value*10 + i;
            if(addValue > max){
                break;
            }
            else{
                result.push_back(addValue);
                buildAnswer(result,max);
            }
        }

    }
};

int main(){
    int n = 13;
    Solution test;
    vector<int> answer = test.lexicalOrder(n);
    for(int i = 0 ;i < answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
