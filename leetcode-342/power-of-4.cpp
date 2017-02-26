/* 这个题涉及到具体的数字运算，需要对几个简单的公式，公式如下：
a^n-b^n =(a-b)[a^(n-1) + a^(n-2) *b +... + a*b^(n-2)+b^(n-1)]  (其中n为正整数)
需要注意一下
*/


#include <iostream>
#include <stdio.h>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int num) {
        return (num > 0)&&((num & (num -1)) == 0)&&((num - 1) % 3 == 0);
    }
};
