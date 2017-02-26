/*
   经过运算会发现实际上每次取得值都是原先的某次值乘以2,3,5算出来的，
   你的代码还可以进一步简化空间复杂度
   这个题的做法真的很不错
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglyNumbers(n,1);int index = 1;
        vector<int> uglyTwoNumbers(n,2); int i = 0;
        vector<int> uglyThreeNumbers(n,3); int j = 0;
        vector<int> uglyFiveNumbers(n,5); int k = 0;
        while( index < n){
            uglyNumbers[index] = min(uglyTwoNumbers[i],min(uglyThreeNumbers[j],uglyFiveNumbers[k]));
            if(uglyNumbers[index] == uglyTwoNumbers[i]){
                uglyTwoNumbers[i+1] = uglyTwoNumbers[i+1] *uglyNumbers[i+1];
                i++;
            }
            if(uglyNumbers[index] == uglyThreeNumbers[j]){
                uglyThreeNumbers[j+1] = uglyThreeNumbers[j+1] *uglyNumbers[j+1];
                j++;
            }
            if(uglyNumbers[index] == uglyFiveNumbers[k]){
                uglyFiveNumbers[k+1] = uglyFiveNumbers[k+1]*uglyNumbers[k+1];
                k++;
            }
            index++;
        }
        return uglyNumbers[n-1];
    }
};

int main(){
    int n = 10;
    Solution test;
    cout<<test.nthUglyNumber(n)<<endl;
    return 0;
}
