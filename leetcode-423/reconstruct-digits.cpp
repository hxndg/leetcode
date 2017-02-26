/*
  这道题花了至少得有3个小时。。。。思路一直在跑偏，什么动态规划啊，深度搜索啊。
  但是这道题的最终解法是将每个数组标志成单独的一位，然后把这一位挑出来，在运算的过程当中，先搜索谁对后面的搜索有影响，此外每个单词选出来的元素必须是这个单词里出现一次的元素，否则统计的时候就会就会出现问题
  很不错的题，一定要记住
  具体的解析，以及为什么searchOrder的顺序很重要可以参考解释
  https://discuss.leetcode.com/topic/63386/one-pass-o-n-java-solution-simple-and-clear/10
*/



#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {
        string words[10] = {"zero","two","six","eight","seven","three","four","one","five","nine"};
        int wordNumber[10] = {0,2,6,8,7,3,4,1,5,9};
        char searchOrder[10] = {'z','w','x','g','s','t','r','o','f','i'};
        vector<int> result(26,0);
        for(int i = 0; i < s.size();i++){
            result[s[i] - 'a']++;
        }
        for(int i = 0;i < 10;i++){
            for(int j = 0;j < words[i].size();j++){
                if(words[i][j] == searchOrder[i]) continue;
                result[ words[i][j] - 'a'] -= result[searchOrder[i] - 'a'];
            }
        }
        string answer;
        for(int i = 0;i<10;i++){
            string part;
            while(result[searchOrder[i] -'a'] > 0){
                part += to_string(wordNumber[i]);
                result[searchOrder[i] - 'a'] --;
            }
            answer += part;
        }
        sort(answer.begin(),answer.end());
        return answer;
    }

};


int main(){
    string s ="owoztneoer";
    Solution test;
    cout<<test.originalDigits(s)<<endl;
    return 0;
}
