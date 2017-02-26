/* 这道题提供了一种基本思路，对于求逆序的数组元素的问题，使用Merge sort可以很巧妙的解决，这是一种标准方式。
   初次之外，还需要注意的是，你第一种的写法非常的复杂，但是很多没必要出现的数组都有了，比方说result存储了逆序的每一个元素，sortedSecondArray存储了已经处理过的第二个数组的元素，
   这些具体的数值在本题当中是没有用处的，不如直接用表示总数的数字代替，这个需要注意，能省时间就省时间，当然时间还是比较接近的，是最后一个例子出的问题说明节省一小点时间即可
   还有一点需要注意的就是move函数的使用，这个函数很不错哦
*/






#include <vector>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;

class Solution {
public:
       /* 下面这种算法本身想法是没有问题的，但是这个方法适用于需要知道每个逆序的组合，因此简单版本的只统计数字版本的从新写了一个，这个版本的result存储了每一个逆序的元素，简单版本只是存储逆序的个数
   void countSmallerByMerge(vector<int> &changeIndex,vector<vector<int>> &result,vector<int>&nums,int start,int end){
       //result和nums是原本的数组，是一一对照的关系，而changeIndex则是变换之后的序号，这个序号对应于原先位置
       if(end - start <= 0)
         return;
       int length = (end - start)/2;
       int middle = start + length;
       countSmallerByMerge(changeIndex,result,nums,start,middle);
       countSmallerByMerge(changeIndex,result,nums,middle+1,end);
       int i = start;   //这个对应于拆分开的上面的数组
       int j = middle+1;  //这个对应于拆分开的下面的数组
       int k = start;   //这个对应于上面两个数组合并时的数组
       vector<int> sortedSecondArray;
       vector<int> tmp; //这部分存储的是已经分配完的部分
       while(i<=middle && j<= end){
           if(nums[changeIndex[i]] < nums[changeIndex[j]] ){
               result[ changeIndex[i]].insert(result[ changeIndex[i]].begin(),sortedSecondArray.begin(),sortedSecondArray.end());
               tmp.push_back(changeIndex[i]);
               i++;
               k++;
           }
           if(nums[changeIndex[i]] > nums[changeIndex[j]]){
               sortedSecondArray.push_back( nums[changeIndex[j]]);
               tmp.push_back(changeIndex[j]);
               j++;
               k++;
           }
       }
       while(i <= middle){
           result[ changeIndex[i]].insert(result[ changeIndex[i]].begin(),sortedSecondArray.begin(),sortedSecondArray.end());
           tmp.push_back(changeIndex[i]);
           i++;
           k++;
       }
       while(j <= end ){
           tmp.push_back(changeIndex[j]);
           j++;
           k++;
       }
       move(tmp.begin(),tmp.end(),changeIndex.begin()+ start);
       return;
   }
   */
   void countSmallerByMerge(vector<int> &changeIndex,vector<int> &result,vector<int>&nums,int start,int end){
       //result和nums是原本的数组，是一一对照的关系，而changeIndex则是变换之后的序号，这个序号对应于原先位置
       if(end - start <= 0)
         return;
       int length = (end - start)/2;
       int middle = start + length;
       countSmallerByMerge(changeIndex,result,nums,start,middle);
       countSmallerByMerge(changeIndex,result,nums,middle+1,end);
       int i = start;   //这个对应于拆分开的上面的数组
       int j = middle+1;  //这个对应于拆分开的下面的数组
       int k = start;   //这个对应于上面两个数组合并时的数组
       int sortedSecondArrayCount = 0;
       vector<int> tmp; //这部分存储的是已经分配完的部分
       while(i<=middle && j<= end){
           if(nums[changeIndex[i]] <= nums[changeIndex[j]] ){
               result[changeIndex[i]] += sortedSecondArrayCount;
               tmp.push_back(changeIndex[i]);
               i++;
               k++;
           }
           if(nums[changeIndex[i]] > nums[changeIndex[j]]){
               sortedSecondArrayCount++;
               tmp.push_back(changeIndex[j]);
               j++;
               k++;
           }
       }
       while(i <= middle){
          result[changeIndex[i]] += sortedSecondArrayCount;
           tmp.push_back(changeIndex[i]);
           i++;
           k++;
       }
       while(j <= end ){
           tmp.push_back(changeIndex[j]);
           j++;
           k++;
       }
       move(tmp.begin(),tmp.end(),changeIndex.begin()+ start);
       return;
   }

    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result(nums.size());
        vector<int> changeIndex(nums.size());
        iota(changeIndex.begin(),changeIndex.end(),0);
        int start = 0,end = nums.size() - 1;
        countSmallerByMerge(changeIndex,result,nums,start,end);
        return result;
    }
};


int main(){
    int sample[4] = {5,2,6,1};
    vector<int> nums(sample,sample+4);
    Solution test;
    vector<int> answer = test.countSmaller(nums);
    for(int i = 0 ;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
