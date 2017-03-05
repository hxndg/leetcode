#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <string.h>

using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == t) return true;
        int k = 0;
        for(int i = 0 ;i < t.size(); i++ ){
            if(s[k] == t[i]){
                k++;
            }
            if(k == s.size()){
                return true;
            }
        }
        return false;
    }
};
