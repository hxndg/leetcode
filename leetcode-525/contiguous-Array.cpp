/*
   这个题实际上提出来一个这样子的问题，我什么时候能够用hash表来代替我想找的查找，而不是使用dp去检查每一个存过的地址
   我个人认为答案是这样子的，当我想求的东西满足的公式就比方说下面的，是一个对每一个变量都一致的形式，而我只关心其中的i或者说j，既然形式是一样的，那么我就能迅速索引到它，进而锁定我想要的东西
                2*(dp[i] - dp[j]) == i - j
   看了标准答案使用的方法，我只想说一句话，fuck my life，真的相当想说fuck my life
   标准方法使用-1来替代1，因此当我发现sum[i,j]==0时，我就知道两个数字出现的次数一样了
   一开始打算使用dp的方法，但是时间复杂度(n^2)太高了，下面是动态规划的代码
        vector<int> dp(nums.size()+1);
        int longestLength = 0;
        for(int i = 1 ; i < nums.size() + 1;i++){
            dp[i] = dp[i-1] + (nums[i-1]==1?1:0);
            for(int j = 0;j <= i; j++){
                if(2*(dp[i] - dp[j]) == i - j && (dp[i] - dp[j])!=0 ){
                    longestLength = max(longestLength,i-j);
                    break;
                }
            }
        }
        return longestLength;
   尝试使用二分解决。
*/
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        /*
        int sum = 0;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i] == 0){
                nums[i] = -1;
            }
        }
        int n = nums.size(),maxLength = 0;
        map<int,int> hashMap;
        for(int i = 0 ; i< nums.size();i++){
            sum += nums[i];
            if(sum == 0){
                maxLength = max(maxLength,i+1);
            }
            map<int,int>::iterator iter = hashMap.find(sum);
            if(iter != hashMap.end()){
                maxLength = max(maxLength,i - iter->second);
            }
            else{
                hashMap.insert(make_pair<int,int>(int(sum),int(i)));
            }
        }
        return maxLength;
        */
        map<int,int> hashMap;
        int maxLength = 0;
        int sum = 0;
        for(int i = 0 ; i < nums.size(); i ++){
            sum += nums[i];
            if( 2*sum == i+1){
                maxLength = max(maxLength,i+1);
            }
            map<int,int>::iterator iter = hashMap.find(i - 2*sum);
            if(iter != hashMap.end()){
                maxLength = max(maxLength,i - iter->second);
            }
            else{
                hashMap.insert(make_pair<int,int>(int(i-2*sum),int(i)));
            }
        }
        return maxLength;
    }



};

int main(){
    int sample[8] = {0,0,1,0,0,0,1,1};
    vector<int> nums(sample,sample + 8);
    Solution test;
    cout<<" answer is "<<test.findMaxLength(nums)<<endl;
    return 0;
}
