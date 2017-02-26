/*
    这个题确实可以用回溯来做，但是这个题为什么使用回溯或者说使用递归不好？问题就出在递归的方法犯了和求斐波那契数列一样的问题，
    递归没有减少问题的出现因此需要使用动态规划，也就是说数组来记下来已经出现的结果,这个题标明了优化的方法，你还需要更深入的思考如何优化算法的问题

*/

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> combineWay(target+1,1);
        if(target == 0) return 1;
        for(int i = 1; i < combineWay.size();i++){
            int ways = 0;
            for(int j = 0; (j < nums.size()) && (i>=nums[j]);j++){
                ways += combineWay[i - nums[j]];
            }
            combineWay[i] = ways;
        }
        return combineWay[target];
    }
};

int main(){
    int sample[3] = {4,2,1},target = 32;
    vector<int> nums(sample,sample+3);
    Solution test;
    int answerNum = test.combinationSum4(nums,target);
    cout<<" There are "<<  answerNum<<" ways" <<endl;
    return 0;
}
