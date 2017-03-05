/*
   我们一开始想要的答案是比较最长的能够匹配的，在相同的条件下我们想要的是字母顺序靠前的，
   那么就可以先按照单词长度，然后按照字母顺序来进行排序，然后找到一个符合的就可以了，非常好的想法
   注释的代码是原本的，等到找到了在比较的方法，而没有注释的代码是正常的，先经过比较排序再直接返回，好很多
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <string.h>

using namespace std;


bool mycomp(const string &a,const string &b){
    return a.size() == b.size()? strcmp(a.c_str(),b.c_str()) < 0 : a.size() > b.size();
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        /*
        if(d.size() == 0) return "";
        vector<int> deleteNum(d.size(),INT_MAX);
        int miniDeleteNum = INT_MAX;
        for(int i = 0 ; i < d.size(); i ++){
            string tmp = d[i];
            int k = 0 ;
            for(int j = 0 ; j < s.size(); j++ ){
                if(s[j] == tmp[k]){
                    k++;
                }
                if(k == tmp.size()){
                    deleteNum[i] = s.size() - tmp.size();
                    miniDeleteNum = min(miniDeleteNum,deleteNum[i]);
                    break;
                }
            }
        }
        if(miniDeleteNum == INT_MAX) return "";
        vector<string> result;
        for(int i = 0 ; i < deleteNum.size();i++){
            if(deleteNum[i] == miniDeleteNum){
                result.push_back(d[i]);
            }
        }
        sort(result.begin(),result.end());
        return result[0];
        */
        if(d.size() == 0) return "";
        sort(d.begin(),d.end(),mycomp);
        for(int i = 0 ; i < d.size(); i++){
            cout<<d[i]<<" ";
        }
        cout<<endl;
        int miniDeleteNum = INT_MAX;
        for(int i = 0 ; i < d.size(); i ++){
            string tmp = d[i];
            int k = 0 ;
            for(int j = 0 ; j < s.size(); j++ ){
                if(s[j] == tmp[k]){
                    k++;
                }
                if(k == tmp.size()){
                    return tmp;
                }
            }
        }
        return "";
    }
};


int main(){
    string s("bab");
    string sample[4] = {"ba","ab","a","b"};
    vector<string> d(sample,sample+4);
  //  d.push_back("plea");
    Solution test;
    cout<<"answer is "<<test.findLongestWord(s,d)<<endl;
    return 0;
}
