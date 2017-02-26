#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        /*  自己写的汉明距离计算，比较麻烦需要两个数字运算。下面的方法会非常简单
        int i = 0 ;
        int j = 0;
        int hammingDistance = 0;
        while( x >0 || y >0 ){
          i = x & 1;
          j = y & 1;
          hammingDistance = hammingDistance + abs(i - j);
          x = x >> 1;
          y = y >> 1;
        }
        return hammingDistance;
        */
        int hammingDistance = 0,n = x ^ y ;
        while(n){
            hammingDistance ++;
            n = n & (n-1);
        }
        return hammingDistance;

    }
};

int main(){
    Solution test;
    int x = 1;
    int y = 4;
    int result = test.hammingDistance(x,y);
    cout<< result <<endl;
    return 0;
}
