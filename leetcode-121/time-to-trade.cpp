#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0;
        int lowestPriceEver = prices[0],profit = 0;
        for(int i = 1; i< prices.size(); i++){
            if(prices[i] < lowestPriceEver){
                lowestPriceEver = prices[i];
            }
            else{
                profit = max( profit,prices[i] - lowestPriceEver);
            }
        }
        return profit;
    }
};


int main(){
    int sample[5] = {7, 6, 4, 3, 1};
    vector<int> nums(sample,sample+5);
    Solution test;
    cout<< "answer is "<< test.maxProfit(nums)<<endl;
    return 0;
}
