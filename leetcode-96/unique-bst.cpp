#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
            for(int i = 1;i < n+1;i++){
                for(int j = 1;j <= i; j++){
                    if(j == 1){
                        dp[i] += dp[i-1];
                        continue;
                    }
                    if(j == i){
                        dp[i] += dp[i-1];
                        continue;
                    }
                    if(j != 1){
                        dp[i] += dp[j-1] * dp[i-j];
                    }
                }
            }
        return dp[n];
    }
};

int main(){
    int n = 2;
    Solution test;
    cout<<"answer is "<<test.numTrees(n)<<" ways"<<endl;
    return 0;
}
