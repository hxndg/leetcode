/*
  标准答案再次使用了滑动窗口方法，我们的目标就是找到最短的窗口或者说是最短的长度不是吗？这个题就是一道典型的找到最短长度的题目，所以滑动窗口非常的合适
  自己的代码使用了map的lower_bound方法，不是很推荐，自己的代码是注释掉的代码
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <map>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /*
        int n = nums.size(),miniSubLength = INT_MAX;
        if(n == 0) return 0;
        vector<int> sumIndex(nums.begin(),nums.end());
        map<int,int> hashMap;
        for(int i = 0 ; i < sumIndex.size();i++){
            if(i != 0){
                sumIndex[i] += sumIndex[i-1];
            }
            hashMap.insert(make_pair<int,int>(int(sumIndex[i]),int(i)));
        }
        if(sumIndex[n-1] < s) return 0;
        for(map<int,int>::iterator iter = hashMap.begin();iter != hashMap.end(); iter++){
            map<int,int>::iterator it = hashMap.lower_bound(iter->first + s );
            if(it != hashMap.end()){
                miniSubLength = min(miniSubLength,it->second - iter->second);
            }
            if(iter->first >= s){
                miniSubLength = min(miniSubLength,iter->second+1);
            }

        }
        return miniSubLength;
        */
        int start = 0,minLength = INT_MAX,sum = 0;
        for(int i = 0 ; i < nums.size();i++){
            sum += nums[i];
            while(sum >= s){
                minLength = min(minLength,i - start +1);
                sum -= nums[start];
                start++;
            }
        }
        if(minLength == INT_MAX){
            return 0;
        }
        else{
            return minLength;
        }
    }
};


int main(){
    int sample[3]= {10,2,3};
    vector<int> nums(sample,sample+3);
    int s = 6;
    Solution test;
    cout<<"answer is "<<test.minSubArrayLen(s,nums)<<endl;
    return 0;
}
