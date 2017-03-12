/*
    这道题虽然看出来是动规了，但是没有想出来状态方程的建立方法，并不能想到利用m和n来建立方程
    主要的问题在于需要解决的变量太多，包括m和n还有字符串最多到哪里的选择，这三个导致这道题很不好想。
    实际上这道题还是提出了一种非常简便的解决方式，那就是一点一点的向后加，每一次选择最大的数值实际上是由原先不要这个数字现在要了总数+1，和原先不要这个数现在还是要不了这个数来做的决定


*/



#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

bool mycomp(const string &a, const string &b){
    int aValue = atoi(a.c_str());
    int bValue = atoi(b.c_str());
    return aValue > bValue;
}


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>>  dp(m+1,vector<int>(n+1,0));
        for(int i = 0 ; i < strs.size(); i ++){
            int zeroCount = 0 , oneCount = 0;
            for(int j = 0 ; j < strs[i].size(); j ++){
                if(strs[i][j] == '0') zeroCount ++;
                if(strs[i][j] == '1') oneCount ++;
            }
            for(int i = m; i >= zeroCount;i -- ) {
                for(int j = n ; j >= zeroCount;j--){
                    dp[m][n] = max(dp[m][n],dp[i-zeroCount][j-oneCount] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

int main(){
    string sample[5] = {"10","0001","111001","1","0"};
    vector<string> strs(sample,sample+5);
    int m = 5,n = 3;
    Solution test;
    cout<<"answer is "<<test.findMaxForm(strs,m,n)<<endl;
    return 0;
}
