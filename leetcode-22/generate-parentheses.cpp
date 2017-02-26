/*
   这个题的想法可以说是解决这种组合插数或者插入符号的非常具有代表性的题目，一个一个插进去即可
   除了这种对应位插入的算法，还有诸如回溯的方法，很值得试一试
*/





#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string currentHave;
        result = generateAnswer("",n,0);
        return result;
    }

    vector<string> generateAnswer(string currentHave,int left,int right){
        vector<string> leftResult;
        vector<string> rightResult;
        if(left == 0 && right == 0){
          vector<string> result;
          result.push_back(currentHave);
          return result;
        }
        if(left > 0){
            string leftAdd = currentHave + "(";
            leftResult = generateAnswer(leftAdd,left-1,right+1);
        }
        if(right > 0){
            string rightAdd = currentHave + ")";
            rightResult = generateAnswer(rightAdd,left,right-1);
        }
        vector<string> result(leftResult.size()+rightResult.size());
        merge(leftResult.begin(),leftResult.end(),rightResult.begin(),rightResult.end(),result.begin());
        return result;
    }
};


int main(){
    int n = 4;
    Solution test;
    vector<string> answer = test.generateParenthesis(n);
    for(int i = 0; i < answer.size();i++){
        cout<<answer[i]<<endl;
    }
    return 0;
}
