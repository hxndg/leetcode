#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>


using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        int size = nums.size();
        if(size == 1 || size == 0{
            return result;
        }
        int lastValue = nums.back();
        vector<int> preNums(nums.begin(),nums.begin()+size - 1);
        vector<vector<int>> preSubsequences =  findSubsequences(preNums);
        result.assign(preSubsequences.begin(),preSubsequences.end());
        for(int i = 0 ; i < preSubsequences.size(); i ++){
            if( lastValue >= preSubsequences[i].back()){
                vector<int> tmp(preSubsequences[i].begin(),preSubsequences[i].end());
                tmp.push_back(lastValue);
                result.push_back(tmp);
            }
        }
        for(int i = 0 ; i < preNums.size();i++){
            if(lastValue >= preNums[i]){
                vector<int> tmp;
                tmp.push_back(preNums[i]);
                tmp.push_back(lastValue);
                result.push_back(tmp);
            }
        }
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        return result;
    }
};

int main(){
    int a[4] = {4,6,7,7};
    vector<int> nums(a,a+4);
    Solution test;
    vector<vector<int>> answer = test.findSubsequences(nums);
    for(int i = 0 ; i < answer.size(); i ++){
        for(int j = 0 ; j < answer[i].size(); j ++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
