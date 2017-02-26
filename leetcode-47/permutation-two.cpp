/*
    虽然这个题并不是只有回溯可以来解，但是回溯确实很好用
*/





#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int> > result;
        vector<int> combination;
        generatePermuteUnique(nums,combination,result);
        return result;
    }

    void generatePermuteUnique(vector<int> &candidates,vector<int> &combination,vector<vector<int>> &result){
        if(candidates.size() == 0){
            result.push_back(combination);
            return ;
        }
        set<int> hashSet;
        for(int i = 0; i < candidates.size(); i++){
            if( hashSet.find(candidates[i]) != hashSet.end()){
                continue;
            }
            else{
                combination.push_back(candidates[i]);
                hashSet.insert(candidates[i]);
                vector<int> tmpCandidates(candidates.begin(),candidates.end());
                tmpCandidates.erase(tmpCandidates.begin()+i);
                generatePermuteUnique(tmpCandidates,combination,result);
                combination.pop_back();
            }
        }
    }
};


int main(){
    int sample[3] = {1,1,2};
    vector<int> nums(sample,sample+3);
    Solution test;
    vector<vector<int> > answer = test.permuteUnique(nums);
    for(int i = 0; i< answer.size();i++){
        for(int j = 0; j< answer.size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
