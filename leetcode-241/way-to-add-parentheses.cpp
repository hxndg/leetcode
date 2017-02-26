/*
   有点像是深度搜索的问题，但是有一些改变
   事实证明上面的感觉并不正确，这道题的扩号的作用是什么？括号改写的并不是具体的数字，括号改写的是符号背后的组合方式
   因此实际上我们是对符号做操作
   这道题也从侧面证明了，当你的思路不正确的时候，进行运算的难度就会大大加大
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int n = input.size();
        for(int i = 0 ; i < n ; i++){
            if(input[i] =='*' || input[i] == '+' || input[i] == '-'){
                vector<int> leftAnswer = diffWaysToCompute(input.substr(0,i));
                vector<int> rightAnswer = diffWaysToCompute(input.substr(i+1));
                for(int j = 0 ;j < leftAnswer.size(); j++){
                    for(int k = 0 ; k < rightAnswer.size(); k++){
                        if(input[i] == '*'){
                            result.push_back(leftAnswer[j] * rightAnswer[k]);
                        }
                        if(input[i] == '+'){
                            result.push_back(leftAnswer[j] + rightAnswer[k]);
                        }
                        if(input[i] == '-'){
                            result.push_back(leftAnswer[j] - rightAnswer[k]);
                        }
                    }
                }
            }
        }
        if(result.size() == 0){
            result.push_back(atoi(input.c_str()));
        }
        return result;
    }
};


int main(){
    string s("15-7*6+24");
    Solution test;
    vector<int> answer = test.diffWaysToCompute(s);
    for(int i = 0 ; i < answer.size();i++){
        cout<<"one answer is "<<answer[i]<<endl;
    }
    return 0;
}
