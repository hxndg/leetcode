/*
   相比于best-trade-3原题，这个题多了best-trade-2的情况，当k值特别大的时候直接每次能赚就卖完了，不需要思考，只有在k值不够大的时候才需要利用动态规划的手段来进行计算。


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if(prices.size() < 2) return 0;
        if(k >= prices.size()/2) return quickSolve(prices);
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

    int quickSolve(vector<int> & prices){
        int result = 0;int i=0;
        while(i + 1 <prices.size()){
            int profit = max(0,prices[i+1] - prices[i]);
            result += profit;
            i++;
        }
        return result;
    }
};
