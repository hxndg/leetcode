#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        for(int i = 0 ;i<nums.size();i++){
            string area(to_string(nums[i]));
            int j = i;
            while( i+1 < nums.size() && nums[i+1] == nums[i] + 1 ){
                i++;
            }
            if(i != j){
                area = area + "->" + to_string(nums[i]);
            }
            result.push_back(area);
        }
        return result;
    }
};

int main(){
    int sample[6] ={0,1,2,4,5,7};
    vector<int> nums(sample,sample+6);
    Solution test;
    vector<string> answer = test.summaryRanges(nums);
    for(int i = 0; i<answer.size();i++){
        cout<< answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
