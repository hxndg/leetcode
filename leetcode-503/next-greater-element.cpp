/*
   这个问题不就是个典型的单调栈么？怎么这都没看出来？
   初次之外还要考虑一点为什么栈对于这种环形的问题非常方便？
   需要思考归并排序的方法为什么对这个并不适用
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <stack>
#include <limits.h>


using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(),-1);
        stack<int> indexStack;
        for(int i = 0; i < nums.size()*2;i++){
            int index = i % nums.size();
            while(!indexStack.empty() && nums[index] > nums[indexStack.top()]){
                result[indexStack.top()] = nums[index];
                indexStack.pop();
            }
            indexStack.push(index);
        }
        return result;



        /*
        vector<int> tmp;
        if(nums.size() == 0) return tmp;
        stack<int>   monotoneStack;
        monotoneStack.push(INT_MAX);
        stack<int>   indexStack;
        vector<int>  result(nums.size(),-1);
        int firstBiggest = INT_MIN;
        for(int index = 0;index < nums.size()*2;index++){
            int i = index % nums.size();
            firstBiggest = max(firstBiggest,nums[i]);
            if( nums[i] <= monotoneStack.top()){
                monotoneStack.push(nums[i]);
                indexStack.push(i);
            }
            if( nums[i] > monotoneStack.top()){
                while(nums[i] > monotoneStack.top()){
                    result[indexStack.top()] = nums[i];
                    monotoneStack.pop();
                    indexStack.pop();
                }
                monotoneStack.push(nums[i]);
                indexStack.push(i);
            }
        }
        for(int i = 0;i<nums.size();i++){
            if(nums[i] == firstBiggest){
                result[i] == -1;
            }
        }
        return result;
        */
    }
};

int main(){
    int a[6] = {1,2,3,2,1};
    vector<int> nums(a,a+5);
    Solution test;
    vector<int> answer = test.nextGreaterElements(nums);
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
