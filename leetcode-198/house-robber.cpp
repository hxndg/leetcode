/*  动态规划简单应用，难度不大

*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0],nums[1]);
        vector<int> result(nums.size());
        result[0] = nums[0];
        result[1] = max(nums[0],nums[1]);
        for(int i = 2;i < nums.size();i++){
            result[i] = max(result[i-2] + nums[i],result[i-1]);
        }
        return result[nums.size() -1];
    }
};

int main(){
}
