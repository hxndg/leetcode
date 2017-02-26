/*
   这个题目本身就是使用回溯来做，自己的做法（也就是注释当中的代码）也确实是回溯，但是为什么自己的代码回溯的速度需要76ms，而标准答案(没有注释掉的代码)只需要16ms就可以完成呢？


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /* 为什么标准答案不需要去重？为什么标准答案时间短暂，你这这种做法讲道理并不能算是回溯
        set< vector<int> > hashSet;
        vector<vector<int>> result;
        for(int i = 0; i < candidates.size();i++){
            int value = target - candidates[i];
            if(value > 0){
                vector<vector<int>> preResult = combinationSum(candidates,value);
                for(int j = 0; j < preResult.size();j++){
                    preResult[j].push_back(candidates[i]);
                    sort(preResult[j].begin(),preResult[j].end());
                    hashSet.insert(preResult[j]);
                }
            }
            if(value == 0){
                vector<int> oneAnswer;
                oneAnswer.push_back(candidates[i]);
                result.push_back(oneAnswer);
            }
        }
        for(set<vector<int>>::iterator iter = hashSet.begin(); iter != hashSet.end();iter++){
            result.push_back(*iter);
        }
        return result;
        */
        sort(candidates.begin(),candidates.end());//一个问题如果这里不适用sort行不行？会怎么样？
        vector<int> combinations;
        vector<vector<int> > result;
        combinationSum(candidates,target,combinations,result,0);
        return result;
    }

    void combinationSum(vector<int>& candidates,int target,vector<int> &combinations,vector<vector<int>> &result,int begin){
        if(target == 0){
            result.push_back(combinations);
        }
        for(int i = begin;i<candidates.size() && target >= candidates[i];i++){
            combinations.push_back(candidates[i]);
            combinationSum(candidates,target-candidates[i],combinations,result,i); // 注意这里的i的意义，实际上i指向了当前可加的对象
            combinations.pop_back();
        }
        return;
    }
};


int main(){
    int sample[7] = {10, 1, 2, 7, 6, 1, 5};
    vector<int> candidates(sample,sample+5);
    int target = 8;
    Solution test;
    vector<vector<int> > result = test.combinationSum(candidates,target);
    for(int i = 0; i < result.size();i++){
        for(int j = 0; j < result[i].size();j ++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
