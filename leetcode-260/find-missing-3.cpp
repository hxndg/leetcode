/* 讲道理遇到很多都是两个数字相同的时候就应该想到使用亦或了，亦或对于解决这种大量相同数字的方法简直是神器啊，真的非常巧妙
   还有一点需要注意的是找最低为1的位置的方法，就在下面的代码里
*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;//std::accumulate(nums.begin(),nums.end(),0,bit_xor<int>());
        for(int i = 0; i < nums.size();i++){
            diff ^= nums[i];
        }
        diff &= -diff;
        vector<int> answer(2,0);
        for(int i = 0; i < nums.size(); i++){
            if((nums[i] & diff) == 0){
                answer[0] ^= nums[i];
            }
            else{
                answer[1] ^= nums[i];
            }
        }
        return answer;
    }
};

int main(){
    int sample[6] = {1,2,1,3,2,5};
    vector<int> nums(sample,sample+6);
    Solution test;
    vector<int> answer = test.singleNumber(nums);
    for(int i = 0;i<answer.size();i++){
        cout<< answer[i]<<endl;
    }
    return 0;
}
