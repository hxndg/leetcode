/*
    标准答案实际上是一个简化过得斐波那契数列，每次要看能不能算上前面的两个数字
    但是经过计算发现即使使用了标准答案的解法，真实的时间复杂度依然没能进化。。。真是尴尬
*/


#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <stdio.h>


using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        /*
        if(s.size() == 0){
            return 0;
        }
        vector<int> answer(s.size(),-1);
        return numDecodings(s,0,answer);
        */
        int n = s.size();
        if(s.size() == 0 || s[0] == '0') return 0;
        vector<int> answer(n+1,0);
        answer[n] = 1;
        answer[n-1] = (s[n-1] == '0'?0:1);
        for(int i = n-2;i >= 0 ; i--){
            if(s[i] == '0') continue;
            if(s[i] < '2' || (s[i] == '2' && s[i+1] < '7')){
                answer[i] = answer[i+2] + answer[i+1];
                continue;
            }
            answer[i] = answer[i+1];
        }
        return answer[0];
    }
    int numDecodings(string s,int index,vector<int> &answer){
        if(index >= s.size()){
            return 1;
        }
        if(answer[index] != -1){
            return answer[index];
        }
        int decodeWays = 0;
        if(s[index] == '0'){
            answer[index] = 0;
            return 0;
        }
        string tmp(s.substr(index,2));
        if(index + 1 < s.size() && (s[index] <'2' || (s[index] =='2'&& s[index+1] <= '6'))){
            decodeWays += numDecodings(s,index + 2,answer);
        }
        decodeWays += numDecodings(s,index+1,answer);
        answer[index] = decodeWays;
        return decodeWays;
    }
};

int main(){
    string s("10");
    Solution test;
    cout<<"answer is "<<test.numDecodings(s)<<endl;
    return 0;
}
