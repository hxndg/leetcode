/*
    解答这个题的重点在于，第一你知道他们必然是有规律的，或者说是对称的，第二：你知道到他具体的生成规则，当然如果你的生成规则错误你也没办法
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        if(n == 0) {
            result.push_back(0);
            return result;
        }
        if(n == 1){
            result.push_back(0);
            result.push_back(1);
            return result;
        }
        vector<int> preResult = grayCode(n - 1);
        result.assign(preResult.begin(),preResult.end());
        for(int i = preResult.size()-1; i >= 0; i--){
            result.push_back(preResult[i] + pow(2,n-1));
        }
        return result;
    }
};

int main(){
    int n = 3;
    Solution test;
    vector<int> answer = test.grayCode(n);
    for(int i = 0 ; i < answer.size(); i ++){
        cout<<answer[i]<< " ";
    }
    cout<<endl;
    return 0;
}
