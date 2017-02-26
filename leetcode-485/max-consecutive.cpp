#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>


using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLength = 0, startPos = 0,endPos = 0;
        for(int i = 0 ;i < nums.size(); i++){
            if(nums[i] == 1) {
                startPos = i;
                while(i < nums.size() && nums[i] == 1  ){
                    i++;
                }
                endPos = i;
            }
            maxLength = max(endPos - startPos,maxLength);
        }
        return maxLength;
    }
};


int main(){
    int sample[7] = {1,1,0,1,1,1,1};
    vector<int> nums(sample,sample+7);
    Solution test;
    cout<< "answer is "<<test.findMaxConsecutiveOnes(nums)<<endl;
    return 0;

}
