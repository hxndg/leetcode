/* 本质上实际是背包问题的变种，背包问题的资料看这里,这里注意一下给二位数组赋值的过程。
   http://love-oriented.com/pack/P01.html  01背包问题讲解
   http://love-oriented.com/pack/P02.html  02背包问题讲解
*/



#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
        }
        if( sum % 2 != 0 )  return false;
        sum /= 2;
        int n = nums.size();
        vector<vector<bool>> answer(n+1,vector<bool>(sum+1,false));

        /*
        vector<vector<bool>> answer(n + 1);
        for(int i = 0 ;i < n+1;i++){
            answer[i].resize(sum+1);
        }
        for(int i = 0 ;i< n+1;i++){
            for(int j = 0;j< sum+1;j++){
                answer[i][j] = false;
            }
        }
        */
        answer[0][0] = true;
        for(int i = 0;i< n+1;i++){
            answer[i][0]= true;
        }
        for(int i = 1;i < n+1;i++){
            for(int j = 1;j< sum+1;j++){
                if(j >= nums[i-1]){
                    answer[i][j] = answer[i-1][j] || answer[i-1][j - nums[i-1]];
                }
                else
                    answer[i][j] = answer[i-1][j];
            }
        }
        return answer[n][sum];
    }
};

int main(){
    int sample[4]= {1,5,11,5};
    vector<int> nums(sample,sample+4);
    Solution test;
    cout<< test.canPartition(nums)<<endl;
    return 0;
}
