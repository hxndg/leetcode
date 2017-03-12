/*
   这道题对于重复元素的想法实在是优雅，什么举个简单的例子：（5,5）这个元素出现的次数是两次，那么我们在选择的途中实际上可以把5看成是一个元素，只不过我们可以控制它出现的次数
   这样子就可以很有效的生成所有的子串
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> numsNoDup(nums.begin(),nums.end());
        numsNoDup.erase(unique(numsNoDup.begin(),numsNoDup.end()),numsNoDup.end());   //制造出来一个无重复的数组
        map<int,int> hashMap;
        for(int i = 0 ; i < nums.size(); i ++){
            hashMap[nums[i]]++;
        }
        vector<vector<int>> result= subsetsWithDup(numsNoDup,hashMap,0);
        /*
        buildResult(nums,combination,result,0);
        sort(result.begin(),result.end());
        result.erase(unique(result.begin(),result.end()),result.end());
        */
        return result;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums,map<int,int>&hashMap,int startPos){               //递归的方法来做
        vector<vector<int>> result;
        if(startPos >= nums.size()){
            vector<int> empty;
            result.push_back(empty);
            return result;
        }
        vector<vector<int>> preResult = subsetsWithDup(nums,hashMap,startPos+1);
        for(int j = 0 ; j < preResult.size(); j ++){
                result.push_back(preResult[j]);
        }
        for(int i = 0; i < hashMap[nums[startPos]];i++ ){
            for(int j = 0 ; j < preResult.size(); j ++){
                preResult[j].push_back(nums[startPos]);
                result.push_back(preResult[j]);
            }
        }
        return result;
    }
    void buildResult(vector<int> &nums,vector<int> &combination,vector<vector<int>>&result,int startPos){  //回溯的方法来做
        for(int i = startPos ; i < nums.size(); i ++){
            combination.push_back(nums[i]);
            result.push_back(combination);
            buildResult(nums,combination,result,i+1);
            combination.pop_back();
        }
        return ;
    }
};

int main(){
    int sample[3] = {1,2,2};
    vector<int> nums(sample,sample+3);
    Solution test;
    vector<vector<int>> answer  = test.subsetsWithDup(nums);
    for(int i = 0 ; i < answer.size(); i ++){
        cout<<"answer is ";
        for(int j = 0 ; j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
