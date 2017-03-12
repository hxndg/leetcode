/*
    标准答案吧这道题转换成了寻找起点和终点的问题，也就是说我们先确定一端，然后确定另外一端
    但是为什么这样子可以极大的简化问题？实际上使我们自己不断的在移动边界，让边界向一边移动
*/


#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       int n = nums.size();
       int i = 0 ,j = n-1;
       vector<int> result(2,-1);
       while(i < j){
           int mid = ( i + j)/2;
           if( nums[mid] < target)
               i = mid+1;
           else
               j = mid;
        }
        if(nums[i] != target)
            return result;
        else
            result[0] = i;
       j = n-1;
       while(i < j){
           int mid = (i+j)/2 + 1;
           if(nums[mid] > target)
               j = mid - 1;
           else
               i = mid;
       }
       result[1] = j;
       return result;
        /*
        int end = nums.size()-1, start = 0;
        return searchRange(nums,target,start,end);
        */
    }
    /*
    vector<int> searchRange(vector<int> &nums,int target,int start,int end){
        vector<int> result;
        if(start > end || nums.size() == 0){
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }
        int mid = (start + end)/2;
        if(nums[mid] < target){
            return searchRange(nums,target,mid+1,end);
        }
        if(nums[mid] > target){
            return searchRange(nums,target,start,mid-1);
        }
        if(nums[mid] == target){
            vector<int> prePart = searchRange(nums,target,start,mid-1);
            vector<int> afterPart = searchRange(nums,target,mid+1,end);
            if(prePart[0] == -1 && afterPart.back() == -1){
                result.push_back(mid);
                result.push_back(mid);
            }
            if(prePart[0] != -1 && afterPart.back() != -1){
                result.push_back(prePart[0]);
                result.push_back(afterPart.back());
            }
            if(prePart[0] != -1 && afterPart.back() == -1){
                result.push_back(prePart[0]);
                result.push_back(mid);
            }
            if(prePart[0] == -1 && afterPart.back() != -1){
                result.push_back(mid);
                result.push_back(afterPart.back());
            }
        }
        return result;
    }
    */
};


int main(){
    int sample[6] = {-1, 7, 7, 8, 8, 10};
    int target = 0;
    vector<int> nums(sample,sample+1);
    Solution test;
    vector<int> answer = test.searchRange(nums,target);
    for(int i = 0 ; i < answer.size();i ++){
        cout<<answer[i]<<" ";
    }
    cout <<endl;
    return 0;
}
