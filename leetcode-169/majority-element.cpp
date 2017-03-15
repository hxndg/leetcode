#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0,candidate = INT_MAX;
        for(int i = 0 ; i < nums.size(); i ++){
            if(nums[i] == candidate){
                count++;
            }
            else{
                if(count == 0){
                    candidate = nums[i];
                    count = 1;
                }
                else{
                    count--;
                }
            }
        }
        return candidate;
    }
};

int main(){
    int sample[10]={1,3,1,4,1,1,5,1,2,1};
    vector<int> nums(sample,sample+10);
    Solution test;
    cout<<"answer is "<<test.majorityElement(nums);
    return 0;
}
