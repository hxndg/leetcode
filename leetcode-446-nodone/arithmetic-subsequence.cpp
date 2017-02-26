/* 对于这道题本身还是存在一些疑问，为什么使用unordered_map的时间复杂度就会低不少，为什么result可以直接加上原本的dp[j][diff]？
相比较而言，这个方法的时间复杂度和使用while的相比又少了多少呢？这些都没有搞清楚
*/

#include <limits.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        /* 时间复杂度一直过不去，这种方法本身是直接的做法，找每个差距，然后算一遍，现在按照leetcode标准答案的做法试试。
        if(A.size() < 3 ) return 0;
        vector<int> arthNum(A.size());
        set<int> changeA;
        for(int i = 0; i < A.size(); i++){
            changeA.insert(A[i]);
        }
        int result = 0;
        for(int i = 0; i < A.size() - 2 ;i++){
            for(int j = i + 1; j < A.size() ; j ++){
                long int diff = A[j] - A[i];
                if(diff > INT_MAX || diff < INT_MIN) continue;
                int times = 1;
                while( changeA.find(A[j] + times * diff) != changeA.end() ){
                    arthNum[i]++;
                    times++;
                }
            }
        }
        for( int i =0;i<arthNum.size();i++){
            result += arthNum[i];
        }
        return result;
        */
        if(A.size() < 3) return 0;
        int result = 0;
        vector<unordered_map<int,int>> dp(A.size()); // vector 是按顺序存贮，每一个数字对应序号对应的位置，unordered_map存储了差距diff和数量count，也就是对应这个diff的结尾的个数
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < i; j++){
                int diff = A[i] - A[j];
                dp[i][diff] += 1;
                if(dp[j].find(diff) != dp[j].end()){
                    dp[i][diff] += dp[j][diff];
                    result += dp[j][diff];
                }
            }
        }
        int tmpResult = 0;
        for(int i =0;i< A.size() ; i++){
            unordered_map<int,int>::iterator it = dp[i].begin();
            while(it != dp[i].end()){
                cout<<it->first<<" "<<it->second<<"***********";
                tmpResult += it->second;
                it++;
            }
            cout<<endl;
        }
        cout<<"tmp Result is"<<tmpResult<<endl;
        return result;
    }
};


int main(){
    int sample[5] = {2,4,6,8,10};
    vector<int> A(sample,sample+5);
    Solution test;
    cout<< test.numberOfArithmeticSlices(A)<<endl;
    return 0;
}
