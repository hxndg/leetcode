#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int middleIndex = nums.size() / 2;
        int miniMoves = 0;
        for(int i = 0; i< nums.size(); i++){
            if(i == middleIndex) continue;
            miniMoves =  miniMoves + abs(nums[i] - nums[middleIndex]);
        }
        return miniMoves;
    }
};
