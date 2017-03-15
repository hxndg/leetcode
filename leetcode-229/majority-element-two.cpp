/*
   非常巧妙的方法，利用的实际上是一个投票的想法，非常赞
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1 = 0 , count2 = 0,candidate1 = INT_MAX,candidate2 = INT_MIN;
        for(int i = 0 ; i < nums.size(); i ++){
            if(nums[i] == candidate1){
                count1++;
            }
            else{
                if(nums[i] == candidate2){
                    count2++;
                }
                else{
                    if(count1 == 0){
                        candidate1 = nums[i];
                        count1 = 1;
                    }
                    else{
                        if(count2 == 0){
                            candidate2 = nums[i];
                            count2 = 1;
                        }
                        else{
                            count1 --;
                            count2 --;
                        }
                    }
                }
            }
        }
        count1 = 0;
        count2 = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] == candidate1){
                count1++;
            }
            if(nums[i] == candidate2){
                count2++;
            }
        }
        vector<int> result;
        if(count1 > nums.size()/3){
            result.push_back(candidate1);
        }
        if(count2 > nums.size()/3){
            result.push_back(candidate2);
        }
        return result;
    }
};


int main(){
    int a[8] = {1,1,1,3,3,2,2,2};
    vector<int> nums(a,a+8);
    Solution test;
    vector<int> result = test.majorityElement(nums);
    for(int i = 0 ; i < result.size(); i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
