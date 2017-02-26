#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        vector<int> section;
        vector<int> result;
        section.push_back(9);
        int times = 9;
        while( times > 0){
            int answer = section.back() * times;
            section.push_back(answer);
            times --;
        }
        section[0] = 10;
        result.push_back(10);
        for(int i = 1;i< section.size();i++){
            result.push_back( result[i-1] + section[i]);
        }
        result[0] = 10;
        if(n > 10) return result[9];
        return result[n-1];
    }
};

int main(){
    Solution test;
    cout<<" n等于-1时,有"<<test.countNumbersWithUniqueDigits(-1)<<endl;
    cout<<" n等于0时,有"<<test.countNumbersWithUniqueDigits(0)<<endl;
    cout<<" n等于1时,有"<<test.countNumbersWithUniqueDigits(1)<<endl;
    cout<<" n等于2时,有"<<test.countNumbersWithUniqueDigits(2)<<endl;
    cout<<" n等于3时,有"<<test.countNumbersWithUniqueDigits(3)<<endl;
    cout<<" n等于4时,有"<<test.countNumbersWithUniqueDigits(4)<<endl;
    cout<<" n等于5时,有"<<test.countNumbersWithUniqueDigits(5)<<endl;
    cout<<" n等于6时,有"<<test.countNumbersWithUniqueDigits(6)<<endl;
    cout<<" n等于7时,有"<<test.countNumbersWithUniqueDigits(7)<<endl;
    cout<<" n等于8时,有"<<test.countNumbersWithUniqueDigits(8)<<endl;
    cout<<" n等于9时,有"<<test.countNumbersWithUniqueDigits(9)<<endl;
    cout<<" n等于10时,有"<<test.countNumbersWithUniqueDigits(10)<<endl;
    cout<<" n等于11时,有"<<test.countNumbersWithUniqueDigits(11)<<endl;
    cout<<" n等于12时,有"<<test.countNumbersWithUniqueDigits(12)<<endl;
    return 0;
}
