/*
   非常正常的想法，而且也是非常正确的想法，应当掌握
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() <= 1) return ;
        int k = -1;
        for(int i = 0 ; i < nums.size() -1; i++){
            if(nums[i] < nums[i+1]){
                k = i;
            }
        }
        if( k == -1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int l = -1;
        for(int i = 0 ; i < nums.size(); i++){
            if(nums[i] > nums[k]){
                l = i;
            }
        }
        swap(nums[l],nums[k]);
        reverse(nums.begin() + k + 1,nums.end());
        return ;
    }
};

int main(){
    int sample[3] = {1,1,2};
    vector<int> nums(sample,sample+2);
    Solution test;
    test.nextPermutation(nums);
    for(int i = 0 ; i < nums.size();i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
