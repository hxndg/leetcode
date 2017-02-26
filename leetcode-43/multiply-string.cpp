#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {

    }
    string multiplyOneDigit(string num1,string num2){  //num2 是那个为1的数字
        int num1Length = num1.size();
        int dealing = num1Length - 1;
        int carry = 0;
        int value = 0;
        while(dealing >= 0){

            carry = (num2[0] -'0') * (num1Length[dealing] - '0');
        }

    }
};
