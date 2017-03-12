#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> twiceNums;
        int length = 0;
        for(int i = 0; i < nums.size(); ){
            int j = 1;
            while(nums[i+1] == nums[i]){
                if(j == 1 ){
                    twiceNums.push_back(nums[i]);
                    j--;
                }
                i++;
            }
            twiceNums.push_back(nums[i]);
            i++;
        }
        nums.swap(twiceNums);
        return nums.size();
    }
};

int main(){
    int a[5] = {0,0,0,0,3};
    vector<int> nums(a,a+5);
    Solution test;
    cout<<"answer is "<<test.removeDuplicates(nums)<<endl;
    for(int i = 0 ; i< nums.size(); i  ++){
        cout<<nums[i]<<endl;
    }
    return 0;
}
