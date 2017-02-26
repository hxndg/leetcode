#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> combination;
        vector<int> candidates(nums.begin(),nums.end());
        generatePermutations(candidates,combination,result);
        return result;
    }

    void generatePermutations(vector<int> &candidates,vector<int>&combination,vector<vector<int>> &result){
        if(candidates.size() == 0){
            result.push_back(combination);
            return;
        }
        for(int i = 0 ; i < candidates.size();i++){
            combination.push_back(candidates[i]);
            vector<int> tmpCandidates(candidates.begin(),candidates.end());
            tmpCandidates.erase(tmpCandidates.begin()+i);
            generatePermutations(tmpCandidates,combination,result);
            combination.pop_back();
        }
    }
};


int main(){
    int sample[3] = { 1, 2, 3};
    vector<int> nums(sample,sample+3);
    Solution test;
    vector<vector<int>> answer = test.permute(nums);
    for(int i = 0; i< answer.size();i++){
        for(int j = 0; j < answer[i].size(); j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
