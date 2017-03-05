/*
    标准答案写的比较简单直接就是对开始位置和结束位置进行计算，你写的迭代方法比较麻烦，但是是正确的。。。尴尬啊
*/


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        if(n == 2){
            return min(nums[0],nums[1]);
        }
        if(nums[0] > nums[n/2]){
            vector<int> nextNums(nums.begin(),nums.begin()+n/2+1);
            return findMin(nextNums);
        }
        if(nums[0] < nums[n/2]){
            vector<int> nextNums(nums.begin()+n/2,nums.end());
            return min(nums[0],findMin(nextNums));
        }
        */

        int start = 0 , end = nums.size()-1;
        while(start < end){
            int mid = (start + end)/2;
            if(nums[start] >nums[mid]){
                end = mid;
                continue;
            }
            if(nums[start] < nums[mid]){
                start = mid + 1;
                continue;
            }
            if(nums[start] == nums[mid]){
                return min(nums[start],nums[end]);
            }
        }
    }
};

int main(){
    int a[8] = {4,5,6,7,11,0,1,2};
    vector<int> nums(a,a+8);
    Solution test;
    cout<<test.findMin(nums)<<endl;
    return 0;
}
