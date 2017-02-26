/*
   时间上可以继续进行优化，不过需要先将数组拍个顺序，剩下的。。。就差不多了
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

struct idSum{
    int firstId;
    int secondId;
};




class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        multimap<int,idSum> hashTable;
        vector<vector<int>> result;
        for(int i = 0 ;i< nums.size();i++){
            for( int j = 0 ;j < nums.size(); j++){
                if(i == j) continue;
                idSum newIndex;
                newIndex.firstId = i;
                newIndex.secondId = j;
                hashTable.insert(make_pair<int,idSum>((int)nums[i]+nums[j],idSum(newIndex)));
            }
        }
        for(int i = 0; i <nums.size() ;i++){
            for(int j = 0; j< nums.size();j++){
                if(i == j) continue;
                pair<multimap<int,idSum>::iterator,multimap<int,idSum>::iterator > range;
                range = hashTable.equal_range(int(target - nums[i] - nums[j]));
                for(multimap<int,idSum>::iterator iter = range.first;iter != range.second;iter++){
                    idSum *tmp = &iter->second;
                    bool duplicate = (i == tmp->firstId) ||(j == tmp->firstId) || (i == tmp->secondId) || (j == tmp->secondId);
                    if( duplicate ){
                        continue;
                    }
                    else{
                        vector<int> oneAnswer;
                        oneAnswer.push_back(nums[i]);
                        oneAnswer.push_back(nums[j]);
                        oneAnswer.push_back(nums[tmp->firstId]);
                        oneAnswer.push_back(nums[tmp->secondId]);
                        sort(oneAnswer.begin(),oneAnswer.end());
                        result.push_back(oneAnswer);
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        vector<vector<int>>::iterator iter;
        iter = unique(result.begin(),result.end());
        if(iter != result.end()){
            result.erase(iter,result.end());
        }
        return  result;
    }
};

int main(){
    int sample[8] = {-3,-2,-1,0,0,1,2,3};
    vector<int> nums(sample,sample+8);
    Solution test;
    vector<vector<int>> result = test.fourSum(nums,0);
    for(int i = 0;i<result.size();i++){
        for(int j = 0;j< result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
