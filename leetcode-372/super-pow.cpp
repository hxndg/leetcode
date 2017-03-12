/*
    一个前置知识 ab%k = (a%k)(b%k)%k

*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(b.size() == 0) return 1;
        int base = 1337,k = b.back();
        b.pop_back();
        return pow(a,k) * pow(superPow(a,b),10) % base;
    }
    int pow(int a,int k){
        int result = 1,base = 1337;
        a = a % base;
        for(int i = 0 ; i < k;i++){
            result= (result * a) % base;
        }
        return result;
    }
};


int main(){
    int a=2,sample[2]={1,0};
    vector<int> b(sample,sample+2);
    Solution test;
    cout<<"answer is"<<test.superPow(a,b)<<endl;
    return 0;
}
