/* 这个题是一道动态规划题，这个题需要注意的地方有三个，其中一个是动态规划的看出来，这是其中一个，
   另一个是边界的数值，是k还是k+1.这一点需要注意，
   最后需要注意一点的是这里面的tmp，tmp是一定范围的最大的值，这个题根据范围的扩大不断的选择范围，188题是这道题的变种，不过算法是一致的.

*/



#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int k = 2;
        int maxGain = 0;
        vector<vector<int>> profit(k + 1,vector<int>(prices.size(),0));
        for(int i = 1; i <= k;i++){
            int tmp = profit[i - 1][0] - prices[0];
            for(int j = 1; j < prices.size();j++ ){
                profit[i][j] = max(profit[i][j-1],prices[j] + tmp);
                tmp = max(tmp,profit[i-1][j] - prices[j]);
                maxGain = max(maxGain,profit[i][j]);
            }
        }
        return maxGain;
    }
};
