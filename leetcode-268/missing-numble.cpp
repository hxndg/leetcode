#include <vector>
#include <iostream>
#include <string>
#include <iostream>
#include <math.h>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i =0;
        int outPos = -1;
        while(i < nums.size()){
            if(nums[i] == 0 ){
                outPos = 0;
                i++;
                continue;
            }
            if(nums[i] != nums[ nums[i] - 1 ]){
                swap(nums[i],nums[ nums[i] - 1]);
            }
            else{
                i++;
            }
        }
        for( i = 0; i < nums.size();i++){
            if( nums[i] != i+1){
                return i+1;
            }
        }
        return 0;
    }
};


int main(){
    int sample[1] = {0};
    vector<int> nums(sample,sample+1);
    Solution test;
    cout << test.missingNumber(nums) << endl;
    return 0;
}
