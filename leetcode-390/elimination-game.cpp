#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        if(n == 1) return 1;
        if((n & 1) == 0) {
            return (n+2) -2*lastRemaining(n/2);
        }
        if((n & 1) == 1){
            return (n+1) - 2*lastRemaining((n-1)/2);
        }
    }
};

int main(){
    int n = 1;
    Solution test;
    while(n <= 9)
        cout<<"answer is "<<test.lastRemaining(n++)<<endl;
    return 0;
}
