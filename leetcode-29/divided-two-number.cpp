#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)){
            return INT_MAX;
        }
        bool test1 = dividend < 0;
        bool test2 = divisor < 0;
        bool negative = (dividend < 0) ^ (divisor <0);
        long long  dvd = labs(dividend);
        long long dvs = labs(divisor);
        if(dvd == 0 || dvd < dvs) return 0;
        int movetimes = 0,originDivisor = dvs;
        while(dvd >= dvs){
            movetimes++;
            dvs = dvs << 1;
        }
        movetimes--;
        dvs = dvs >> 1;
        if(negative){
            return -1 * (pow(2,movetimes) + divide(dvd- dvs,originDivisor));
        }
        else{
            return (pow(2,movetimes) + divide(dvd-dvs,originDivisor));
        }
    }
};

int main(){
    int dividend = 2147483648,divisor = 1;
    Solution test;
    cout<<"answer is "<< test.divide(dividend,divisor)<<endl;
    return 0;
}
