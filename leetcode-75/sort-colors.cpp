/*
    标准答案给出了一种非常巧妙的解法，可以俗称为换位解法,自己的解法是注释的解法
    写这道题的时候出现了一个很有意思的错误,错误如下，没有写i > start限制条件,为什么这个样子呢？当nums[i]和自己调换时，start+1了，然后i还是自己先调换然后start又加了1，导致直到换了一个其他的数值填补了start的位置才终止，last那一块同理
            while(nums[i] == 0) {  //问题就出现在这里，出现问题的原因是因为swap[i]没有对于自己换自己进行判断，导致多进行了两步操作
                swap(nums[i],nums[start]);
                start++;
            }

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
        int redCount = 0,whiteCount = 0,blueCount = 0;
        for(int i = 0 ; i < nums.size() ; i ++){
            redCount += (nums[i] == 0);
            whiteCount += (nums[i] == 1);
            blueCount += (nums[i] == 2);
        }
        whiteCount += redCount;
        blueCount += whiteCount;
        for(int i = 0 ; i < nums.size();i++){
            int color = 0;
            if(i > redCount-1 && i <whiteCount )
                color = 1;
            if(i > whiteCount-1)
                color = 2;
            nums[i] = color;
        }
        */

        int last = nums.size()-1,start = 0;
        for(int i = 0 ; i <= last;i++){
            while(nums[i] == 2 && i < last){
                 swap(nums[i],nums[last]);
                 last -- ;
            }
            while(nums[i] == 0 && i > start) {  //问题就出现在这里，出现问题的原因是因为swap[i]没有对于自己换自己进行判断，导致多进行了两步操作
                swap(nums[i],nums[start]);
                start++;
            }
        }
    }
};

int main(){
    int a[7] = {0,1,0,2,1,0,2};
    vector<int> nums(a,a+7);
    Solution test;
    test.sortColors(nums);
    for(int i = 0 ; i < nums.size() ;i ++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
