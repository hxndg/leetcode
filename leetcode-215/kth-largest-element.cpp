/*
这道题做的时候实际上自己把他做复杂了，本质上非常简单。。。。但是需要复习一下找第k个数的方法
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i;
        /*
        for(i = nums.size() -1;(i>=0) && (k > 0);i--){
            while(i >= 1 && nums[i] == nums[i-1]){
              i--;
            }
            k--;
        }
        */
        return nums[nums.size()-k ];//nums[i+1];
    }
};


int main(){
    int a[1] = {1};
    vector<int> nums(a,a+1);
    Solution test;
    cout<<test.findKthLargest(nums,1)<<endl;
    return 0;
}
