
/* 我表示第一种方法，也就是simple java solution的想法是再是巧妙，真的是巧妙啊,基本想法是基于hash。因为重复出现的次数最多只有2，那么利用取负值就类似于取了hash算法，利用abs还不干扰原本的数据。真的是巧秒啊。
   完全的厉害。
  第二种方法，本质上是一种叫做counting sort的方法，其利用的本质上是通过查大小来定位置，但是我依然没看懂标准答案的意思，哈哈哈,但是counting sort对于被排序的对象具有严格的要求，必须是整数，而且范围必须已经知道
  第二种方法本质上是将每一个数字根据他的数值，把它放到自己该在的位置上，因为大部分数字最多出现一次，因而缺失数字的位置最终会被出现两次的数字占住，而已经换到位置上上的数字不会有任何改变。

*/


#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        vector<int> res;
        for(int i = 0; i<nums.size(); i++){
            int index = abs(nums[i]) -1;
            if( nums[index] < 0){
                res.push_back( abs( nums[i] ));
            }
            nums[index] = - nums[index];
        }
        return res;
        */
        vector<int> res;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != nums[nums[i]-1]) swap(nums[i], nums[nums[i]-1]);
            else i++;
        }
        for(i = 0; i< nums.size();i++){
            if(nums[i] != i+1){
                res.push_back(i+1);
            }
        }
        return res;
    }
};

int main(){
    int sample[8] = {4,3,2,7,8,2,3,1};
    vector<int> nums(sample,sample+8);
    Solution test;
    vector<int> answer = test.findDisappearedNumbers(nums);
    for(int i = 0;i< answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
