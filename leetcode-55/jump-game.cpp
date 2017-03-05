/*
    你的做法还是麻烦了不少，两个内层循环使得复杂度上升到了n^2的级别实际上我们是想看看能不能reach到最后一个元素，
    而最后一个元素能reach到就直接反返回了，所以最根本的就是直接把边界标示出来
    注释掉的代码是自己的代码，没有注释的代码是标准答案，时间复杂度是O(n)
    实际上我觉得需要思考的问题是，这个题为什么时间复杂度是n，怎么样能看出来时间复杂度为n？

*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        /*
        vector<bool> canIjump(n,false);
        canIjump[0] = true;
        for(int i = 1 ; i < n ; i ++){
            for(int j = i-1 ; j >= 0 ; j --){
                if( (canIjump[j] == true) && ((j+nums[j]) >= i)){
                    canIjump[i] = true;
                    break;
                }
            }
        }
        return canIjump[n-1];
        */
        int reach = 0;
        for(int i = 0 ; i <= reach && reach < n; i ++){ // 浮动的边界，真是巧妙
            reach = max(i + nums[i],reach);
        }
        if(reach >= n-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){
    int sample[5] = {0,1,1,1,1};
    vector<int> nums(sample,sample+2);
    Solution test;
    if(test.canJump(nums)){
        cout<<"yes I can"<<endl;
    }
    else{
        cout<<"nope,I can't"<<endl;
    }
    return 0;
}
