/*以后能用vector的地方还是使用vector吧，除了是要对字符串赋值，其他情况下使用原始声明方式太容易出错了
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <limits.h>
#include <utility>

using namespace std;

struct numFreq{
    int number;
    int frequency;
    numFreq(int a):number(a),frequency(0){}
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> result;
        for(int i = 0;i<nums.size();i++){
            map<int,int>::iterator iter = result.find(nums[i]);
            if(iter != result.end()){
                iter->second ++;
            }
            else{
                result.insert(make_pair<int,int>(int(nums[i]),1));
            }
        }
        vector<vector<int>> order(nums.size());
        for(map<int,int>::iterator it = result.begin();it != result.end();it++){
            order[it->second-1].push_back(it->first);
        }
        vector<int> answer;
        for(int i = nums.size()-1;i>=0 && k >0;i--){
            for(int j = 0;j < order[i].size() && k>0;j++){
                answer.push_back(order[i][j]);
                k --;
            }
        }
        return answer;
    }
};



int main(){
    int sample[6] ={1,1,1,2,2,3};
    int k = 2;
    vector<int> nums(sample,sample+6);
    Solution test;
    vector<int> answer = test.topKFrequent(nums,k);
    for(int i = 0 ;i < answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
