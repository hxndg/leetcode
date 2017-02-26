/*
 *非常有趣的一道题，相比之下到时比较简单，通过率也很高，这道题值得注意的是一种方法是直接
 把所有的剩余数补足到hash表中，另外一种是一个一个算，没有了再补足进去，给后面的数字用，这个题用的是第二种方法
 我写的注释里是第一种方法，这两种方法第二种能用第一种会出现自己补足自己的问题。可以注意一下这种想法，等到发现没有了，需要了再往里面送。
*/

#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int> & nums,int target){
             map<int,int> residue;
             for(int i = 0;i<nums.size();i++){
                 int remain = target - nums[i];
                 //residue.insert(make_pair(remain,i));   //the correct answer put the number into the residue later
             /*
             for(int i=0;i<nums.size();i++){
                 if(it != residue.end()){
                     cout<<i<<" "<<it->second;
                     vector<int> answer;
                     answer.push_back(i);
                     answer.push_back(it->second);
                     return answer;
                 }
             }
             */
                 map<int,int>::iterator it;
                 it = residue.find(nums[i]);
                 if(it!=residue.end()){
                     vector<int> answer;
                     answer.push_back(it->second);
                     answer.push_back(i);
                     cout<<i<<" "<<it->second;
                     return answer;
                 }
                 residue.insert(make_pair(remain,i));
            }
          }
};

int main(){
    int a[4] = {2,7,11,15};
    vector<int> test(a,a+4);
    Solution one;
    one.twoSum(test,9);
}
