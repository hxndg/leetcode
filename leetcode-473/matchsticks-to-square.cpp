/*
   关于这道题的思考还没有结束，这道题提出来了很多问题
   1 什么是np问题，如何定义np问题
   2 搜索，或者说深度搜索如何优化？如何优化搜索问题，数组的顺序有没有影响，应当如何拜访节点的选择
   3 深搜能不能利用dp的结果
*/


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool dfs(vector<int> &sidesLength,const vector<int> &matches,int index,int target){
      if(index == matches.size()){
          return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
      }
      for(int i = 0; i < 4; i++){
          if(sidesLength[i] + matches[index] > target) continue; ;
          sidesLength[i] += matches[index];
          if(dfs(sidesLength,matches,index+1,target)){
              return true;
          }
          sidesLength[i] -= matches[index];
      }
      return false;
    }
    bool makesquare(vector<int>& nums) {
        if(nums.empty()) return false;
        int target = 0;
        for(int i = 0 ; i < nums.size() ;i ++){
            target += nums[i];
        }
        if(target %4 != 0){
            return false;
        }
        vector<int>  sidesLength(4,0);
        sort(nums.begin(),nums.end());
        return dfs(sidesLength,nums,0,target/4);
    }
};

int main(){
    int sample[5] = {1,1,2,2,2};
    vector<int> nums(sample,sample + 5);
    vector<int> preHalf;
    Solution test;
    cout<<"answer is "<<test.makesquare(nums)<<endl;
    return 0;
}
