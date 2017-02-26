/*
   我的问题是这个题目能不能用回溯来做呢？回溯的过程是不是用贪心来解可以呢？
   答案是不能，问题出在两个方面，第一个对空间要求太高，第二点对时间的要求实际上是要将所有的组合都遍历一遍,因此是不正确而且不方便的
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(),coins.end());
        vector<int> coinNums(amount+1,INT_MAX);
        coinNums[0] = 0;
        for(int i = 1 ; i < amount+1 ; i++){
            for(int j = 0; j < coins.size() && i >= coins[j]; j++){
                if(i - coins[j] == 0){
                    coinNums[i]= 1;
                    break;
                }
                if(coinNums[i - coins[j]] == INT_MAX){
                    continue;
                }
                coinNums[i] = min(coinNums[i],1 + coinNums[i - coins[j]]);
            }
        }
        return coinNums[amount]==INT_MAX?-1:coinNums[amount];
        /*
        if(amount == 0) return 0;
        sort(coins.begin(),coins.end());
        vector<int> combination;
        vector<vector<int>> answer;
        int begin = coins.size()-1;
        while(amount < coins[begin]){
            begin--;
        }
        if(begin == -1){
             return -1;
        }
        generateCombine(coins,amount,combination,begin,answer);
        if(answer.size() != 0){
            int minLength = INT_MAX;
            for(int i = 0;i<answer.size();i++){
                minLength = min(minLength,int(answer[i].size()));
            }
            return minLength;
        }
        return -1;
        */
    }

    void  generateCombine(vector<int> &candidates,int target,vector<int> &combination,int begin,vector<vector<int>> &answer){
        if(target == 0){
             answer.push_back(combination);
             return;
        }
        for(int i = begin; i >= 0; i--){  //有一点很值得思考，为什么递增顺序进行考虑的时候需要在for循环的终止条件里写上target >= candidates[i]，而这里不需要呢？
            if(target >= candidates[i]){
                combination.push_back(candidates[i]);
                generateCombine(candidates,target - candidates[i],combination,i,answer);
                combination.pop_back();
            }
        }
    }
};

int main(){
    int sample[4] = {186,419,83,408},amount = 6249;
    vector<int> coins(sample,sample+4);
    Solution test;
    cout<<"answer is "<<test.coinChange(coins,amount)<<endl;
    return 0;
}
