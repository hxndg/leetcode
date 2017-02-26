/* 这道题也是一个想法的问题，将数组向左右两侧分成两个不同的相乘的元素，很巧妙。
*/


#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> productFromBack(nums.size(),1);
        vector<int> productFromStart(nums.size(),1);
        vector<int> answer(nums.size(),1);
        for(int i = 1;i < nums.size(); i++){
            productFromStart[i] =  productFromStart[i - 1] * nums[i - 1];
        }
        for( int i = nums.size() - 2 ; i >= 0 ; i--){
            productFromBack[i] = productFromBack[i + 1] * nums[i + 1];
        }
        for( int i = 0; i < nums.size(); i++){
            answer[i] = productFromBack[i]*productFromStart[i];
        }
        return answer;
    }
};


int main(){
    int sample[4] = {1,2,3,4};
    vector<int> nums(sample,sample+4);
    Solution test;
    vector<int> answer = test.productExceptSelf(nums);
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
