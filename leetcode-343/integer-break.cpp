/*
  注释是自己想的方法，用的是动态规划，
  提示说是存在复杂度为O(n)的算法,确实存在，因为每个数字都可以拆成2和3组成的增加的乘积，简单来说每个数的最大乘积都是由前面可以拆成2/3的组合造出来，因此整体可以拆成2/3的组合
  那么为什么拆成2/3比较好，而拆成包含2/3之外的组合不好呢？因为拆成其他的组合时乘法因子都不是这个乘法因子所能乘出来的最大的因数
  https://discuss.leetcode.com/topic/43055/why-factor-2-or-3-the-math-behind-this-problem
  上面的链接给出了非常详尽的数学方面的证明，当然自己的理解并没有什么大的问题

*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        if(n ==2) return 1;
        if(n == 1) return 0;
        int threeCount = n/3;
        while( (n - threeCount*3) %2 != 0){
            threeCount--;
        }
        int twoCount = (n - threeCount*3)/2;
        return pow(3,threeCount)*pow(2,twoCount);


        /*
        vector<int> result(n+1,0);
        if(n == 2) return 1;
        if(n == 1) return 1;
        if(n == 3) return 2;
        for(int i = 1; i < n + 1;i++){
            int maxValue = 0;
            for(int j = 1;j <= i/2;j++){
                maxValue = max(maxValue,result[i-j]*result[j]);
            }
            result[i] = (i>maxValue?i:maxValue);
        }
        return result[n];
        */
    }
};


int main(){
    int n = 10;
    Solution test;
    cout<<test.integerBreak(n)<<endl;
    return 0;
}
