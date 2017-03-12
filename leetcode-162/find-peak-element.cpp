/*
   这道题最直接的想法就是直接找，时间复杂度是O(n)级别的，
   但是这道题实际上可以把时间复杂度所见到O(logN)级别，方法就是因为我们并不关心具体的peak在哪里，我们可以每次把peak缩减一半

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        /*
        if(nums.size() == 1) return 0;
        for(int i = 0 ; i < nums.size(); i++){
            if(i == 0) {
                if(nums[i] > nums[i+1]){
                    return i;
                }
            }
            if(i == nums.size()-1){
                if(nums[i] > nums[i-1]){
                    return i;
                }
            }
            if(i !=0 && i != nums.size()-1){
                if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                    return i;
                }
            }
        }
        */
        return helper(nums,0,nums.size()-1);
    }
    int helper(vector<int> &nums,int startPos,int endPos){
        if(startPos == endPos){
            return startPos;
        }
        else{
            if((endPos - startPos) == 1){
                return nums[endPos]>nums[startPos]?endPos:startPos;
            }
            int mid = (startPos+endPos)/2;
            if( nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            if(nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]){
                return helper(nums,mid+1,endPos);
            }
            return helper(nums,startPos,mid-1);
        }
    }
};

int main(){
    int a[4] = {1,2,3,1};
    vector<int> nums(a,a+4);
    Solution test;
    cout<<"answer is "<<test.findPeakElement(nums)<<endl;
    return 0;
}
