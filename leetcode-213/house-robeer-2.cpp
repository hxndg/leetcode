/* 相比之下这道题比house-robber就多了一个限制条件，就是房子是环形的，最后一个房子需要注意不能和第一个房子碰上，因此这里的问题如果拆分成两个部分从[1,n-1]与[2,n]之间怎么选择的问题就会简单很多
   如果只是说考虑最后两个不能相碰就会发现，出现了不要第一个的求和比要第一个求和更大的情况。这种情况除非拆分否则很难考虑到。总之，这种处理方法很巧妙，值得记住
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

        vector<int> result1(nums.size() - 1);
        vector<int> result2(nums.size() - 1);
        result1[0] = nums[0];
        result1[1] = max(nums[0],nums[1]);
        result2[0] = nums[1];
        result2[1] = max(nums[1],nums[2]);
        for(int i = 2;i < nums.size() - 1;i++){
            result1[i] = max(result1[i-2] + nums[i],result1[i-1]);
        }
        for(int i = 2;i < nums.size() -1;i++){
            result2[i] = max(result2[i-2] + nums[i+1],result2[i-1]);
        }
        return max(result1[nums.size() -2],result2[nums.size() -2]);
    }
};

int main(){
    int sample[6]= {2,2,4,3,2,5};
    vector<int> nums(sample,sample+6);
    Solution test;
    cout<< test.rob(nums)<<endl;
    return 0;
}
