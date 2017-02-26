/* 这道题的想法比较直接，就是每次看最近乘进来的因子是正数还是负数，当然需要考虑清除如果是第一个正数，或者是第一个负数的情况下怎么搞等等问题 

*/



#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 1){
           return nums[0];
        }
        int answer = 0,biggestPositive = 0,minimumNegative = 0;
        bool firstNegative = true;
        bool firstPositive = true;
        for(int i = 0;i < nums.size() ;i++){
            if( nums[i] > 0 ){
                biggestPositive = max( biggestPositive * nums[i],nums[i]);
                minimumNegative = minimumNegative * nums[i];
            }
            if( nums[i] < 0){
                int k = biggestPositive * nums[i];
                biggestPositive = minimumNegative * nums[i];
                minimumNegative = min(k,nums[i]);
            }
            if(nums[i] == 0){
                minimumNegative = 0;
                biggestPositive = 0;
            }
            answer = max(biggestPositive,answer);
      }
        return answer;
    }
};


int main(){
    int sample[5] = {2,3,-2,4,-3};
    vector<int> nums(sample,sample+5);
    Solution test;
    cout<< "answer is "<<test.maxProduct(nums)<<endl;
    return 0;
}
