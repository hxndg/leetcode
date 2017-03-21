/*
    这道题竟然简化到了o(n)的时间复杂度！如此的巧妙，广搜的简单应用！
    实际上，可以总结出来对于求最短的距离的问题，使用bfs搜索是非常合适，而且巧妙的做法
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        /*
        if(nums.size() == 1) return 0;
        vector<int> jumpNums(nums.size(),-1);
        for(int i = nums.size()-2;i >= 0;i--){
            int step = INT_MAX;
            for(int j = nums[i] ; j > 0; j--){
                if(i+j < nums.size() - 1 && jumpNums[i+j] != -1){
                    step = min(step,1 + jumpNums[i+j]);
                }
                if(i+j >= nums.size()-1){
                    step = 1;
                    break;
                }
            }
            if(step != INT_MAX){
                jumpNums[i] = step;
            }
        }
        return jumpNums[0];
        */
        if(nums.size() < 2) return 0;
        int jumpNums = 0,reach = 0,nextReach = 0,i = 0;
        while(true){
            jumpNums++;
            for(; i <= reach;i++){
                nextReach = max(nextReach,nums[i] + i);
            }
            reach = nextReach;
            if(reach >= nums.size() - 1){
                return jumpNums;
            }
        }
        return 0;
    }
};

int main(){
    int sample[5] = {2,3,0,1,4};
    vector<int> nums(sample,sample+5);
    Solution test;
    cout<<"answer is "<<test.jump(nums)<<endl;
    return 0;
}
