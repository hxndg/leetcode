/*
   滑动窗口，当end - start + 1 - maxCharCount <= k,就把窗口向后滑动，，滑完了，就有最大的长度是多少了，
   这个方法真的好巧妙,很不错的一道题，

*/


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <string>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int start = 0,end = 0,result = 0,maxCharCount = 0;
        for(end = 0;end < s.size();end++){
            count[s[end] - 'A']++;
            if( count[s[end] - 'A'] > maxCharCount ){
                maxCharCount = count[s[end] - 'A'];
            }
            while(end - start + 1 - maxCharCount > k){
                count[s[start] - 'A']--;
                start++;
                for(int i = 0; i < 26;i++){
                    if(maxCharCount < count[i]){
                        maxCharCount = count[i];
                    }
                }
            }
            result = max(result,end - start + 1);
        }
        return result;
    }
};

int main(){
    string s("AABABBA");
    Solution test;
    cout<<"answer is "<<test.characterReplacement(s,1)<<endl;
    return 0;
}
