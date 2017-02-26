/* 同样是一个元素一个元素插入考虑，这个题不需要考虑的东西很多还是非常简单的
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result = nums[0],biggestSum = nums[0];
        for( int i = 1;i<nums.size();i++){
            if(biggestSum >= 0){
                biggestSum += nums[i];
            }
            if(biggestSum < 0){
                biggestSum = nums[i];
            }
            result = max(result,biggestSum);
        }
        return result;
    }
};


int main(){
    int sample[9] = {-2,1,-3,4,-1,2,1,-5,4};
    vector<int> nums(sample,sample+9);
    Solution test;
    cout<<" answer is "<< test.maxSubArray(nums)<<endl;
    return 0;
}
