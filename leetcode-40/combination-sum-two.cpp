#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector< vector<int>> result;
        vector<int> combinations;
        combinationSum(candidates,target,combinations,result,0);
        return result;
    }
    void combinationSum(vector<int> &candidates,int target,vector<int> &combinations,vector<vector<int>> &result,int begin){
        if(target == 0){
            result.push_back(combinations);
            return;
        }
        for(int i = begin; i < candidates.size() && target >= candidates[i];){
            combinations.push_back(candidates[i]);
            combinationSum(candidates,target - candidates[i],combinations,result,i+1);
            combinations.pop_back();
            while(candidates[i+1] == candidates[i]){
                i++;
            }
            i++;
        }
    }
};

int main(){
    int sample[7] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(sample,sample+6);
    int target = 8;
    Solution test;
    vector<vector<int>> answer = test.combinationSum2(candidates,target);
    for(int i = 0;i < answer.size();i++){
        cout<<endl;
        for(int j = 0; j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
    }
    return 0;
}
