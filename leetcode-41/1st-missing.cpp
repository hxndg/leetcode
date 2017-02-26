/* 这道题依然是利用了leetcode-442的第二种做法，就是将元素按照需要放到位置上，
   可以将数字分为这么几类，一种是范围在1-n的数字，这类数字经过不断的变换最终会放到序号加1的位置上
   第二种数字为大小大于n的数字，这类数字最终会在上面数字的范围之外，第三类数字为数值小于0的数字
   而我们要寻找的第一个missing的正数，实际上第一个不在它应该在的位置上的数字。因为用上面的方法排序以后
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        while(i < nums.size()){
            if(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] -1 ]){
                swap(nums[i],nums[ nums[i] - 1]);
            }
            else {
                i++;
            }
        }
        for(int i = 0; i< nums.size();i++){
            if( nums[i] != i+1 ){
                return i+1 ;
            }
        }
        return n+1;
    }
};


int main(){
    int a[6] = {-1,4,2,1,9,10};
    vector<int> sample(a,a+6);
    Solution test;
    cout<<test.firstMissingPositive(sample)<<endl;
    return 0;
}
