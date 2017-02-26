/*
   讲道理这个不就是从1到n能够表示乘i×i的数的个数么？不就是sqrt（n）么？你的想法算了半天就是sqrt。。。
   绕远了。。。。
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        /*
        vector<int> lightBulb;
        for(int i = 1; i <= n;i++){
            int squareRoot = sqrt(i);
            if( (squareRoot*squareRoot) == i ){
                lightBulb.push_back(i);
            }
        }
        return lightBulb.size();
        */
        return sqrt(n);
    }
};

int main(){
    int n = 4;
    Solution test;
    cout<<n<<" bulbs,"<<test.bulbSwitch(n)<<" on"<<endl;
    return 0;
}
