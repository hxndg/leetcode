/*
值得注意的一个是九行的c++答案，真的非常巧妙，值得再次思考，另一个是对于iterator的考虑，当你删除一个元素之后，还需不需要再进行iterator+1的操作呢？
*/




#include <vector>
#include <map>
#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      /*
        unordered_map<char,int> wordTable;
        unordered_map<char,int>::iterator it;
        int longestLength = 0;
        int substringLength=0;
        for(int i=0;i<s.size();i++){
            if(wordTable.find(s[i]) == wordTable.end()){
                substringLength++;
            }
            else {
                it = wordTable.find(s[i]);
                int repeatPosition = it->second;
                for(unordered_map<char,int>::iterator deleteIt = wordTable.begin();
                    deleteIt != wordTable.end();
                    deleteIt++){
                        //if(deleteIt->second <= it->second)  //一开始老是报错，报的问题是runtime error问题就出在这里，it和deleteIt重合的时候it已经被删除了，因此出现了指向NULL的it就会报错
                        if(deleteIt->second <= repeatPosition)
                            wordTable.erase(deleteIt);
                    }
                substringLength = i - repeatPosition;
                }
            wordTable.insert(make_pair(s[i],i));
            if(substringLength > longestLength){
                longestLength = substringLength;
            }
        }
        return longestLength;
        */
        int longestLength = 0;
        int substringLength = 0;
        vector<char> noneRepeatString;
        for(int i = 0; i< s.size();i++){
            if( find(noneRepeatString.begin(),noneRepeatString.end(),s[i]) == noneRepeatString.end() ){
                substringLength++;
            }
            else {
                vector<char>::iterator repeatPositionIter = find(noneRepeatString.begin(),noneRepeatString.end(),s[i]);
                int repeatPosition = repeatPositionIter - noneRepeatString.begin();
                noneRepeatString.erase(noneRepeatString.begin(),repeatPositionIter+1);
                //substringLength = i - repeatPosition;   这里出现了第二个问题，问题如下，i是整个字符串里的标签，是相对于整个string的起始地址，而substring是相对于最长的无重复的字符串，因此i会很大，二repeatPosition是立足于substring的，因此这个值会不断的增大，运算出现了错误，更正为下面的一条
                substringLength = substringLength - repeatPosition;
            }
            noneRepeatString.push_back(s[i]);
            longestLength= max(longestLength,substringLength);
        }
        return longestLength;
    }
};

int main(){
    string  sample("abcabcbb");
    Solution test;
    int result = test.lengthOfLongestSubstring(sample);
    cout<<"string is "<<sample<<endl;
    cout<<"lenght Of LongestSubstring is "<<result;
    return 0;
}
