/*
    这个题为什么能做到O(n)的时间复杂度呢？因为我的考虑是单向的，我只需要在一个长度变量减少的情况下去思考高度变量，而不需要考虑其他的方面
    这个很重要
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxContain = min(height[0],height.back()) * (height.size()-1);
        int i = 0 , j = height.size() - 1;
        while(i < j){
            int preHeight = height[i],lastHeight = height[j];
            if(height[i] >= height[j]){
                while(height[j] <= lastHeight && i < j ){
                    j--;
                }
                maxContain = max(maxContain,min(height[i],height[j]) * ( j - i ));
            }
            if(height[i] < height[j]){
                while(height[i] <= preHeight && i < j ){
                i++;
                }
            maxContain = max(maxContain,min(height[i],height[j]) * ( j - i ));

            }
          }
        return maxContain;
    }
};

int main(){
    int sample[4] = {1,2,4,3};
    vector<int> height(sample,sample+4);
    Solution test;
    cout<<"answer is "<<test.maxArea(height)<<endl;
    return 0;
}
