#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 , end = nums.size()-1,miniIndex = 0;
        while(start < end){
            int mid = (start + end)/2;
            if(nums[start] >nums[mid]){
                end = mid;
                continue;
            }
            if(nums[start] < nums[mid]){
                start = mid;
                continue;
            }
            if((end - start) == 1){
                miniIndex = nums[end]<nums[start]?end:start;
                break;
            }
        }
        vector<int> firstPart(nums.begin(),nums.begin()+miniIndex);
        vector<int> lastPart(nums.begin()+miniIndex,nums.end());
        int index1 = halfSearch(firstPart,target);
        int index2 = halfSearch(lastPart,target);
        if(index1 == -1){
            if(index2 == -1){
                return -1;
            }
            else{
                return miniIndex + index2;
            }
        }
        else{
            return index1;
        }
    }
    int halfSearch(vector<int>& nums,int target){
        int start = 0 , end = nums.size()-1;
        while(start < end){
            int mid = (start + end)/2;
            if((end - start ) == 1){
                if(nums[end] == target){
                    return end;
                }
                else{
                    return -1;
                }
            }
            if(nums[mid] > target){
                end = mid;
                continue;
            }
            if(nums[mid] <target){
                start = mid;
                continue;
            }
            if(nums[mid] == target){
                return mid;
            }

        }
        return -1;
    }
};

int main(){
    int a[8] = {4,5,6,7,0,1,2,3};
    vector<int> nums(a,a+8);
    Solution test;
    cout<<"mini Index is "<<test.search(nums,3)<<endl;
    return 0;
}
