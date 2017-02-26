/* 这个题，有一个非常重要的一方面，就是这个题这里的Arithmetic Number要求必须是连续的，连续的是什么意思，连续就可以
利用动态规划的方式来思考问题，而不是简单的使用所谓的直接硬算的方法。
*/



#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if( A.size() < 3 ) {
            return 0;
        }
        int result = 0;
        vector<int> dp(A.size(),0);
        if(A[2] - A[1] == A[1] - A[0]){
            dp[2] = 1;
        }
        for(int i = 3; i < A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                dp[i] = dp[i-1] + 1;
            }
        }
        for(int i = 0; i< A.size();i++){
            result += dp[i];
        }
        return result;
    }
};


int main(){
    int sample[4]={1,2,3,4};
    vector<int> A(sample,sample+4);
    Solution test;
    int answer = test.numberOfArithmeticSlices(A);
    cout<<"answer is "<<answer<<endl;
    return 0;
}
