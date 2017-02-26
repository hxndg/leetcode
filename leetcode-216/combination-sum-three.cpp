#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> candidates;
        for(int i  = 0; i < 9 ; i++){
            candidates.push_back(i+1);
        }
        vector<int> combination;
        vector<vector<int>> result;
        generateCombination(candidates,k,combination,result,0,n);
        return result;
    }

    void generateCombination(vector<int> &candidates,int k,vector<int> &combination,vector<vector<int>> &result,int begin,int target){
        if( k==0 && target == 0){
            result.push_back(combination);
            return;
        }
        for(int i = begin; i < candidates.size() && k > 0 && target >= candidates[i];i++){
            combination.push_back(candidates[i]);
            generateCombination(candidates,k-1,combination,result,i+1,target-candidates[i]);
            combination.pop_back();
        }
    }
};

int main(){
    int n = 9,k = 3;
    Solution test;
    vector<vector<int>> answer = test.combinationSum3(k,n);
    for(int i = 0; i< answer.size();i++){
        for(int j = 0; j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
