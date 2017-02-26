/*
  这个题我只能说orz，基本原理是不去寻找具体的pair直接根据为运算来判断能不能得到某个result，利用的原理是：
  假设A,B是能够拿到最大值的整数对，那么必然有A ^ B = result,从而必然有 result ^ A = B 与 result ^ B = A,每次我都只多运算一位，即result后面除了我已经确定可以拿到，然后还有一个我猜测能够拿到的位置，后面都是0
  然后问题就出现了，如何判断result是不是可行的呢？由于每次我都存储了这些数对和11...000...的&运算的记过，因此如果我发现确实存在result满足上一行的两个运算条件，我就知道result确实是可行的，从而我确定了这一位result是否可以拿到，
  按照上面所述的方法，我就可以一点一点确定我是不是可以取到这个result了
  非常巧妙，而且非常正常的想法,很值得一试
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int max = 0, mask = 0;
        for(int i = 31;i >= 0; i--){
            mask = mask | (1 << i);
            set<int> hashSet;
            for(int j = 0;j < nums.size();j++){
                hashSet.insert(mask & nums[j]);
            }
            int tmp = max | (1 << i);
            for(set<int>::iterator iter = hashSet.begin();iter != hashSet.end();iter++){
                if(hashSet.find(tmp ^ (*iter)) != hashSet.end()){
                    max = tmp;
                    break;
                }
            }
        }
        return max;
    }
};


int main(){
    int sample[6] = {3,10,5,25,2,8};
    vector<int> nums(sample,sample+6);
    Solution test;
    cout<<test.findMaximumXOR(nums)<<endl;
    return 0;
}
