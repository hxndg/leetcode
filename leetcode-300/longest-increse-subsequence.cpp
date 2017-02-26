/* 实际上应该算是动态规划，不过想法很简单。但是第一次想的时候陷入了僵局，
   最好是算上包含每个最后元素的最长的递增数列，从而保证正确性。
*/


#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0 ) return 0;
        int maxLength = 1;
        vector<int> longestLength(nums.size(),0);
        longestLength[0] = 1;
        for(int i = 1;i < nums.size();i++){
            longestLength[i] = 1;
            for(int j = i-1;j >= 0;j--){
                if( (nums[i] > nums[j])){
                    longestLength[i] = max(longestLength[j] + 1,longestLength[i]);
                }
            maxLength = max(longestLength[i],maxLength);
            }
        }
        return maxLength;
    }
};

int main(){
    int sample[9] = {1,3,6,7,9,4,10,5,6};
    vector<int> nums(sample,sample+9);
    Solution test;
    cout<< test.lengthOfLIS(nums)<<endl;
    return 0;
}
