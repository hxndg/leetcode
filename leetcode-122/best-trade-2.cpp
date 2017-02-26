#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size() < 1) return 0;
        int result = 0;int i=0;
        while(i + 1 <prices.size()){
            int profit = max(0,prices[i+1] - prices[i]);
            result += profit;
            i++;
        }
        return result;
    }
};
