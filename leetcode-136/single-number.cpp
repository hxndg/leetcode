#include <vector>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int i = 0;i < nums.size();i++){
            result ^= nums[i];
        }
        return result;        
    }
};
