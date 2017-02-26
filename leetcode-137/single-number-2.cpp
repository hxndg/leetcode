/* 详尽的解释，很不错
https://discuss.leetcode.com/topic/11877/detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
假设重复的次数是k，那么统计这32位整数，每个数位上出现的1的次数，总的次数对3取余必然会剩一个数位，要么0，要么1，而最后剩下的那个数字，也就是我们多余的那个数字
但是这道题的详尽标准答案，给出了解释具体的算法步骤的方法，并没有使用32个counter（尽管这是最直接的想法），它使用的是最少的位数*32位整数来代表这个位数。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> nums) {
      int counter[32];
      int i, j;
      int res = 0;

      for(i=0; i<32; i++)
          counter[i] = 0;

      for(i=0; i<nums.size(); i++)
      {
          for(j=0; j<32; j++)
          {
              if(nums[i] & (1<<j))
              counter[j]++;
          }
      }

      for(i=0; i<32; i++)
      {
          if(counter[i]%3)
              res |= 1<<i;
      }

      return res;
    }
};


int main(){
    return 0;
}
