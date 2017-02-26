/*
这个题可以记一下，本身是dfs深度搜索，然后需要判断边界去除太短或者太长的字符串，去除完字符串以后利用深度优先。
深度有限说到底就是几种情况一列，然后每一个情况往下进，进不去的话回来的时候回退状态。
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        string str1,str2,str3,str4;
        vector<int> part(4,0);
        int top = 0,times = 0;
        string pinedString;
        vector<string> result;
        continueAnalysis(s,top,times,pinedString,result);
        return result;
    }
    void continueAnalysis(string s,int top,int times,string pinedString,vector<string> &result){
        if(s.size() == 0 || s.size()>12) return;
        if(times == 3) {
            string str = s.substr(top,s.size()- top);
            int num = atoi(str.c_str());
            if(num > 255|| (num != 0 && str[0]=='0') ||(num == 0 && str.size()>=2 )){
                return ;
            }
            else{
                result.push_back(pinedString + str);
                return ;
            }
        }
        for(int i = 1; i <= 3;i++){
            if(top + i > s.size() -1) continue;
            string str = s.substr(top,i);
            int num = atoi(str.c_str());
            if( num > 255 || (num != 0 && str[0]=='0') ||(num == 0 && str.size()>=2)) continue;
            continueAnalysis(s,top+i,times+1,pinedString+str+'.',result);
        }
    }
};

int main(){
    string str("0000");
    Solution test;
    vector<string> answer = test.restoreIpAddresses(str);
    for(int i =0;i<answer.size();i++){
        cout<< answer[i]<<endl;
    }
    return 0;
}
