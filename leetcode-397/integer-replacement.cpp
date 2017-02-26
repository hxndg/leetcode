/*
    非常有意思的一道题，本质上是将一个数字从二进制（举个例子）11101101通过右移或者+1，或者-1操作变成01
    自己的算法对内存的要求太高了，需要分配太多的内存也会影响性能,使用递归的做法没做出来，只有使用直接的分析方法比较简答。
    经过分析当n 大于 3时，如果出现了11那么+1带来的耗损为1，而却能至少节省2，如果一位一位的递减那么不带来耗损但是每次遇到一个奇数位进行加减1的操作会十分耗时
    而且我们不需要进行任何存储分配的操作对时间的消耗也会减少。这个题需要记住
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
      if(n == INT_MAX) return 32;
      int count = 0;
      while(n != 1){
        if( (n & 1) == 0){
          n = n >> 1;
        }else{
            if(n == 3 || countOneNums(n-1) < countOneNums(n+1)){
                n = n - 1;
            }
            else{
                n = n + 1;
            }
        }
        count++;
      }
      return count;
    }

    int integerReplacementMyVersion(int n) {
        vector<int> moveTimes(n+2,0);
        moveTimes[2] = 1;
        for(int i = 3;i < n + 1;i = i+2){
            moveTimes[i+1] = moveTimes[(i+1)/2] + 1;
            moveTimes[i] = min(moveTimes[i+1]+1,moveTimes[i-1]+1);
        }
        return moveTimes[n];
    }

    int countOneNums(int n){
        int count = 0;
        while( n > 0 ){
            n = n & (n-1);
            count++;
        }
        return count;
    }
};


int main(){
    int n = 20000000;
    Solution test;
        cout<<test.integerReplacement(n)<<endl;
    return 0;
}
