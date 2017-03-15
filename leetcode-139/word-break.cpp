/*
    这道题是典型的搜索问题，但是没有做出来，问题出在没有解决对已经探索过的点记忆的问题，需要注意
    我自己的第一种想法实际上是深度搜索，这种方法需要遍历整个解空间，但是这种算法只能通过27/34个测试样例，
    然而我并没有想出来怎么剪枝,实际上剪枝真的可以做出来这道题吗？为什么标准答案有一种使用bfs方法的解决呢？
    实际上这道题使用dfs是可以做出来的，那么为什么dfs会有错误的情况呢？因为很多重复的情况出现了因此使用一个map<string,vector<string>> 能够有效地记住这道题的解法
*/



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
        set<string> hashSet;
        int longestWord = 0;
        for(int i = 0 ; i < wordDict.size();i++){
            int size = wordDict[i].size();
            longestWord = max(longestWord,size);
            hashSet.insert(wordDict[i]);
        }
        if(s.size() == 0) return false;
        return wordBreak(s,hashSet,longestWord);
        */
        set<string> hashSet;
        for(int i = 0 ; i < wordDict.size();i++){
            int size = wordDict[i].size();
            hashSet.insert(wordDict[i]);
        }
        vector<bool> dp(s.size() + 1);
        dp[0] = true;
        for(int i = 1 ; i < s.size()+1;i++){
            for(int j = i - 1;j >= 0 ;j--){
                string tmp = s.substr(j,i-j);
                if((hashSet.find(tmp)!= hashSet.end()) && dp[j] == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
    bool wordBreak(string s, set<string> &hashSet,int longestWord){
        if(s.size() == 0) return true;
        for(int i = longestWord-1 ; i >= 0 ;i --){
            if(s.size() < i+1) continue;
            string tmp = s.substr(0,i+1);
            if(hashSet.find(tmp) != hashSet.end()){
                string left = s.substr(i+1);
                if( wordBreak(left,hashSet,longestWord) ){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    string sample[2] = {"leet","code"};
    vector<string> wordDict(sample,sample+2);
    string s("leetcode");
    Solution test;
    cout<<"answer is "<<test.wordBreak(s,wordDict);
    return 0;
}
