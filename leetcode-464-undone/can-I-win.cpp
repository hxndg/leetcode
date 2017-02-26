#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int biggest = maxChoosableInteger,target = disiredTotal;
        int sumAll = 0;
        vector<int> numbers(biggest,0);
        for(int i = 0;i < biggest;i++){
            sumAll += i+1;
            numbers[i] = i+1;
        }
        for(int i = 0;i < biggest;i++){
            if(sumAll - nums[i] < disiredTotal) return true;
        }
        for(int i = 0; i< biggest;i++){
            vector<int> leftValue = numbers;
            leftValue.erase(leftValue.begin()+i);
            if(deepSearch(leftValue,target - nums[i],false)){
                return true;
            };
        }
        return false;
    }
    bool deepSearch(vector<int> &leftValue,target,bool 1thToDo){
        int n = leftValue.size();
        int sumAll = 0;
        for(int i = 0 ; i < n;i++){
            sumAll += leftValue[i];
        }
        for(int i = 0;i < n ;i++){
            if()
        }
    }
};
