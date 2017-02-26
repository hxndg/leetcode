#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        if(n == 0) return 0;
        uint32_t x = n & (n - 1);
        int i = 1;
        while(x > 0 ){
            x = x & (x-1);
            i++;
        }
        return i;
    }
};

int main(){
    uint32_t sample =   4294967295;
    Solution test;
    cout<< test.hammingWeight(sample)<<endl;
    return 0;
}
