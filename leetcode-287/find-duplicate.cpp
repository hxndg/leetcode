/*这道题是一个抽屉法则的晓得应用，讲道理而言，如果这个题不是针对整数，那么这个题就很有问题。
但是就是脑子想歪了，导致完全想不到怎么搞，抽屉法则，这一点很值得注意.
如果count > mid对应的“槽”位的话，可以认为是前面肯定有重复的数字,
如果count < mid对应的“槽”位的话，可以认为是后面的槽多
表示我绝对是蒙了。。。。这个题利用鸽笼原理，他的搜索过程和具体是s[i]是没有直接关系的，
他是从新遍历从而做到的，和你想的完全是不相关的,不过这种做法确实巧很有意思
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int high = nums.size() -1;
        int low = 0;
        while(low < high){
            int mid = (high + low)/2;
            int count = 0;
            for(int i = 0; i < nums.size();i++){
                if( nums[i] <= mid){
                    count++;
                }
            }
            if( count > mid ){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }

};


int main(){
  int sample[3] = {1,1,2};
  vector<int> tmp(sample,sample+3);
  Solution test;
  cout<< test.findDuplicate(tmp)<<endl;
  return 0 ;
}
