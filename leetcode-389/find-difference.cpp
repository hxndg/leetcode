#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int i = 0,j = 0,result = 0;
        while(i < s.size()){
            result ^= s[i];
            i++;
        }
        while(j < t.size()){
            result ^= t[j];
              j++;
        }
        return result;
    }
};

int main(){
    string s = "abcd";
    string t = "abcde";
    Solution test;
    char answer = test.findTheDifference(s,t);
    cout<<answer<<endl;
    return 0;
}
