/*
   这是一个dp问题，为什么没想到呢？
   除此之外这道题可以使用bfs搜索，bfs搜索方法依赖的同样是任何一个perfect square必然是小于它的perfect square的集合采用bfs方式进行搜索的话必然能够找到他的值,但是bfs的方法最终空间复杂度吵了
   以及数学方法求解。
   解析在这里：https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics/2



*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <queue>

using namespace std;


class Solution {
public:
    int numSquares(int n) {
        /*
        int  minWay = 0;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0;
        for(int i = 1; i< n+1;i++){
            for(int j = sqrt(i); j >=0;j--){
                dp[i] = min(dp[i],dp[i- j*j]+1);
            }
        }
        return dp[n];
        */
        queue<int> bfsQueue;
        int squareRoot = sqrt(n);
        vector<int> minerOne(squareRoot + 1,0);
        queue<int> stepQueue;
        for(int i = 0; i <= squareRoot;i++){
            minerOne[i] = i*i;
        }
        int minStep = 0;
        bfsQueue.push(n);
        stepQueue.push(0);
        while(!bfsQueue.empty()){
            int bfsTarget = bfsQueue.front();
            int stepTarget = stepQueue.front();
            for(int i = 1; i <= sqrt(bfsTarget);i++){
                int leftValue = bfsTarget - i*i;
                bfsQueue.push(leftValue);
                if(leftValue== 0) return stepTarget + 1;
                stepQueue.push(stepTarget+1);
            }
            bfsQueue.pop();
            stepQueue.pop();
        }
    }

};

int main(){
    int n = 1535;
    Solution test;
    cout<<test.numSquares(n)<<endl;
    return 0;
}
