/*
   这个题除了使用递归之外，答案中给了一种非常有意思的答案，可以参考下，使用bit manipulate来进行操作。下面注释掉的代码是使用递归做的
   没有注释的代码是使用未操作进行运算的
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        /*
        int n =nums.size();
        vector< vector<int> > result;
        if(n == 0){
            vector<int> empty;
            result.push_back(empty);
            return result;
        }
        vector<int> subNums(nums.begin(),nums.begin()+n-1);
        vector<vector<int> > previousResult = subsets(subNums);
        for(int i = 0; i < previousResult.size();i++){
              result.push_back(previousResult[i]);
              previousResult[i].push_back(nums[n-1]);
              result.push_back(previousResult[i]);
        }
        return result;
        */

        int n = nums.size();
        int types = pow(2,n);
        vector< vector<int> > result(types);
        for(int i = 0 ; i < nums.size();i++){
            for(int j = 0; j < types ; j++){
                if( (j >> i) & 1 ){
                    result[j].push_back(nums[i]);
                }
            }
        }
        return result;
    }
};

int main(){
    int sample[3] = {1,2,3};
    vector<int> nums(sample,sample+3);
    Solution test;
    vector<vector<int>> result = test.subsets(nums);
    for(int i = 0; i < result.size();i++){
        for(int j = 0; j < result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
