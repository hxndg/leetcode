/*
    这个题的复杂度实际上是n^2级别的，但是你写的版本看上去像是n^3的级别。。。。j和i之间有一个固定的关系，因此不需要第三个for了。。。。
    https://discuss.leetcode.com/topic/76327/c-dp-solution-with-explanation
    不过leetcode上的dp的方法空间复杂度简单很多
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return true;
        vector<vector<vector<int> > >dp(n+1,vector<vector<int>>(n,vector<int>(n,0)));
        for(int k = 1; k < n+1;k++){
            for(int i = 0;i < n;i++){
                for(int j = i; j < n;j++){      //实际上这里可以直接简化的。。。。复杂度是n^2级别，因为k的长度每次都是固定的，因此实际上不需要再写第三个for了。。。
                    if(j - i + 1 != k) continue;
                    if( k== 1 && (i == j)) dp[k][i][j] = nums[i];
                    else{
                        if(j == i+1){
                            dp[k][i][j] = max(nums[i],nums[j]);
                            continue;
                        }
                        int sumBefore = nums[i] + min(dp[k-2][i+2][j],dp[k-2][i+1][j-1]);
                        int sumAfter = nums[j] + min(dp[k-2][i][j-2],dp[k-2][i+1][j-1]);
                        dp[k][i][j] = max(sumBefore,sumAfter);
                    }
                }
            }
        }
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum += nums[i];
        }
        if(2*dp[n][0][n-1] >= sum){
            return true;
        }
        return false;
    }
};


int main(){
    int sample[4] = {1,5,233,7};
    vector<int> nums(sample,sample+4);
    Solution test;
    if(test.PredictTheWinner(nums)){
        cout<<"I can win!"<<endl;
    }
    else{
        cout<<"I can't win!"<<endl;
    }
    return 0;
}
