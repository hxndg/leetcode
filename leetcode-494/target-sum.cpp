/*
  这道题我依然没有想出来，脑子里对于这种挑出来数组求和的思路还是不清晰，
  应当记住对于这种给定数字并且求和的问题，往往都能转换成两个变的集合转换成一个变的集合，需要知道两个变的集合也是这个题的难点，这个题的难点就在这里。
  巧妙的将两个集合转换成2倍的一个集合=(target  + 集合的总和)/2的问题，真的是十分巧妙，需要记住
  这个实际上是背包问题，真是令人惊诧，不过应该早就有这样子的想法
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      int sumAll = 0,numsLength = nums.size();
      for(int i = 0 ;i < numsLength;i++){
          sumAll += nums[i];
      }
      if((sumAll + S) & 1 != 0 || sumAll < S){
          return 0;
      }
      int target = (sumAll + S)/2;
      vector<vector<int> > result(nums.size()+1,vector<int>(target+1,0));
      result[0][0] = 1;
      for(int i = 1; i <= nums.size();i++){
          for(int j = 0;j < target+1;j++){
              if( j >= nums[i-1]){
                  result[i][j] = result[i-1][j] + result[i-1][j-nums[i-1]];
              }
              else{
                  result[i][j] = result[i-1][j];
              }
          }
      }
      return result[nums.size()][target];
    }
};


int main(){
    int a[5] = {1, 1, 1, 1, 1};
    vector<int> nums(a,a+5);
    int S = 3;
    Solution test;
    cout<<test.findTargetSumWays(nums,S)<<endl;
    return 0;
}
