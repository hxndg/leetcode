/*
   注释的方式同样是动态规划，但是却是错误的答案，很令人费解，
   使用改编自标准答案的动态规划方法就可以正确，这点很奇特。
   为什么直接使用价值不行呢？这道题的另一个启示就是能够使用动态规划解决两个的时候就最好不要使用麻烦的for
   换句话说，思考这里为什么使用二维动态规划？因为我们的解依赖于两个条件一个是他的起始位置，一个是他的终结位置。


*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n,vector<int>(n,0));
        return getAnswer(dp,0,n-1);
    }
    int getAnswer(vector<vector<int>> &dp, int startPos,int endPos){
        if(endPos <= startPos) return 0;
        if(dp[startPos][endPos] != 0) return dp[startPos][endPos];
        int maxValue = INT_MAX;
        for(int i = startPos;i<=endPos;i++){
            int tmp = i+1+ max(getAnswer(dp,startPos,i-1),getAnswer(dp,i+1,endPos));
            maxValue = min(maxValue,tmp);
        }
        dp[startPos][endPos] = maxValue;
        return maxValue ;
    }

};


int main(){
    Solution test;
    int n = 1;
    while(n < 21){
        cout<<"n is "<<n<<",cost is "<<test.getMoneyAmount(n)<<endl;
        n++;
    }

    return 0;
}
