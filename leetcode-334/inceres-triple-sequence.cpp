#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> sequence(2,INT_MAX);
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] < sequence[0]){
                sequence[0] = nums[i];
            }
            else if(nums[i] > sequence[0] && nums[i] < sequence[1]){
                sequence[1] = nums[i];
            }
            else if(nums[i]>sequence[1]){
                return true;
            }
            else{
                continue;
            }
        }
        return false;
    }
};

int main(){
    int sample[4] ={2,4,-2,-3};
    vector<int> nums(sample,sample+4);
    Solution test;
    cout<<test.increasingTriplet(nums)<<endl;
    return 0;
}
