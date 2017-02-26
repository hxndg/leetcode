/*
   又是一道随机问题，这个问题的关键在于如果每次交换的时候都是随机的那么，我能不能说生成的shuffle数列是随机的呢？
   应当是可以的，有一个标准答案给的shuffle方案是
   int swapPlace = rand() %(result.size() - i );
   swap(result[i],result[i+swapPlace])
   这个又为什么是正确的呢？
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return this->nums;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> result = nums;
        for(int i = 0;i<result.size();i++){
            int swapPlace = rand()% result.size();
            swap(result[i],result[swapPlace]);
        }
        return result;
    }
};
