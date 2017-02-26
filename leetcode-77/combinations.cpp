#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> candidates(n,0);
        for(int i = 0; i < candidates.size(); i++){
            candidates[i] = i + 1;
        }
        vector<int> combination;
        int rightNumCount = k,currentHave = 0;
        generateCombine(candidates,rightNumCount,combination,result,0);
        return result;
    }

    void generateCombine(vector<int> & candidates,int rightNumCount,vector<int> &combination,vector<vector<int>> &result,int currentHave){
        if(rightNumCount == 0){
            result.push_back(combination);
            return;
        }
        for(int i = currentHave ; i < candidates.size();i++){
            combination.push_back(candidates[i]);
            generateCombine(candidates,rightNumCount-1,combination,result,i + 1);
            combination.pop_back();
        }
    }
};


int main(){
    int n = 3,k = 3;
    Solution test;
    vector< vector<int>> answer = test.combine(n,k);
    for(int i = 0 ;i < answer.size(); i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
