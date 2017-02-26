#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() < 2){
            return s;
        }
        int minStart = 0,maxLength = 0;
        for(int i = 0; i <s.size();){
            if (s.size() - i <= maxLength / 2) break;
            int k = i ,j = i;
            while( k < s.size() - 1 && s[k+1] == s[k]){
                k++;
            }
            i = k + 1;   //忘了这一步，导致死循环，然后就没出来了
            while( k< s.size() -1 && j > 0 && s[k+1] == s[j - 1] ){ //这里忘记了需要先验证j>0然后再验证后面的可以拓展，因而导致了runtime error，很尴尬
                k++;
                j--;
            }
            int length = k - j + 1;
            if(maxLength < length){
                maxLength = length;
                minStart = j;
            }
        }
        return s.substr(minStart,maxLength);
      }
};


int main(){
    Solution test;
    string sample("babad");
    string result = test.longestPalindrome(sample);
    cout<< result<<endl;
    return 0;
}
