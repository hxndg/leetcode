/*
   直接暴力算，每两个数字得一个hamming distance的算法太复杂了，
   使用整体的每一位看一次太巧秒了


*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int sum = 0,times = 32;
        while( times-- >0){
            int zeroTimes = 0,oneTimes = 0;
            for(int i = 0;i < nums.size();i++){
                int lastBit = nums[i] & 1;
                nums[i] = nums[i] >> 1;
                if(lastBit == 1){
                    oneTimes++;
                }
                else{
                    zeroTimes++;
                }
            }
            sum += zeroTimes*oneTimes;
        }
        return sum;
    }
};

int main(){
    int a[3] ={4,14,2};
    vector<int> nums(a,a+3);
    Solution test;
    cout<<"answer is "<< test.totalHammingDistance(nums);
    return 0;
}
