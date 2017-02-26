/* leetcode 的标准答案非常的好，好在哪里呢？不需要使用任何复杂的数据结构，不需要使用任何麻烦的算法，就是排一遍序，
然后建立标示，从前面或者从后面开始找，有序的数组大大减少了需要话费的预支时间，而利用指示从头开始和结尾的两个标示大大减少了话费的时间。
这个题可以关注一下
*/
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <algorithm>

using namespace std;





class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*    注释的部分是自己写的方法，这个方法在leetcode上的消耗时间太大了，超过了应该有的范畴，所以注视掉了
        class node{
        public:
        int value;
        int value2;
        node(int i, int j){
            value = i;
            value2 = j;
       }
       };

        vector <vector<int>> result;
        multimap<int,node> wanted;
        for(int i = 0; i < nums.size();i++){
            for(int j = 0;j < nums.size();j++){
                if(i == j){
                    continue;
                }
                int sum = nums[i] + nums[j];
                node *tmp = new node(i,j);
                wanted.insert(make_pair(sum,*tmp));
            }
        }
        for(int i = 0; i< nums.size();i++){
            int residue = 0 - nums[i];
            std::pair <multimap<int,node>::iterator,multimap<int,node>::iterator> ret;
            ret = wanted.equal_range(residue);
            for(multimap<int,node>::iterator it=ret.first;it != ret.second;++it){
                if(  i != it->second.value && i != it->second.value2){
                    int bigValue = max(nums[i],max(nums[it->second.value],nums[it->second.value2]));
                    int minValue = min(nums[i],min(nums[it->second.value],nums[it->second.value2]));
                    int midValue = nums[i] + nums[it->second.value]+nums[it->second.value2] - bigValue - minValue;
                    vector<int> oneAnswer;
                    oneAnswer.push_back(bigValue);
                    oneAnswer.push_back(midValue);
                    oneAnswer.push_back(minValue);
                    result.push_back(oneAnswer);
                }
            }
        }
        sort(result.begin(), result.end());
        res.erase(unique(result.begin(), result.end()), result.end());
        return result;
        */
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i = 0;i < nums.size();i++){
        int target = - nums[i];
        int font = i + 1;
        int back = nums.size() - 1;
        while(font < back){
            int sum = nums[font] + nums[back];
            if(sum < target){
                font ++ ;
            }
            else if( sum > target){
                back --;
            }
            else{
                vector<int> triple(3,0);
                triple[0] = nums[i];
                triple[1] = nums[font];
                triple[2] = nums[back];
                res.push_back(triple);
                cout<< triple[0]<<" "<< triple[1]<< " " <<triple[2]<<endl;
                while(font < back && nums[font] == triple[1]){
                    font ++;
                }
                while(font < back && nums[back] == triple[2]){
                    back --;
                }
            }
        }
        while( i+1 < nums.size() && nums[i+1] == nums[i]){
            i++;
        }
      }
        return res;
    }
};


int main(){
    int array[15] = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    vector<int> nums(array,array+15);
    Solution tmp;
    vector <vector<int>> result = tmp.threeSum(nums);
    return 0 ;
}
