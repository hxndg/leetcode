/*
   事实证明想得太多了，没找到优化到n的做法，只有优化到n^2的方法，还可以。
*/



#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums){
        if(nums.size() == 0){
            return vector<int>();
        }
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> dp;
        int longestLength = 0,longestIndex = -1;
        for(int i = 0 ; i < n;i++){
          int tmp = -1;
          for(int j = 0 ; j < i;j++ ){
              if((nums[i] % nums[j]==0) && ((tmp == -1)||(dp[tmp].size() < dp[j].size()))){
                  tmp = j;
              }
          }
          if(tmp != -1){
              dp.push_back(dp[tmp]);
          }
          else{
              vector<int> newOne;
              dp.push_back(newOne);
          }
          dp[dp.size()-1].push_back(nums[i]);
          if(dp[i].size() > longestLength){
              longestLength = dp[i].size();
              longestIndex = i;
          }
        }
        return dp[longestIndex];
    }
};

int main(){
    int sample[5] = {2,3,4,9,8};
    vector<int> nums(sample,sample+5);
    Solution test;
    vector<int> answer = test.largestDivisibleSubset(nums);
    for(int i  = 0; i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
