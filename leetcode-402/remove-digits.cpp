/*  这个题的想法比较简单，但是需要注意一点，这里申请的字符数组长度是整个数组的最长的，它是通过整个回写的方式来覆盖字符，方法很巧妙，不需要判断到没到位置。这个需要注意！


*/



#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() - k == 0 ) return "0";
        int digital = num.size() - k;
        char little[num.size()];
        int index = 0;
        for(int i = 0; i< num.size();i++){
            while(index > 0 && little[index-1]>num[i] && k>0 ){
                index--;
                k--;
            }
            little[index++] = num[i];
        }
        int startPos = 0;
        while(startPos < digital && little[startPos]=='0'){startPos++;}
        if(startPos == digital){
            return "0";
        }
        else {
            string answer(little,startPos,digital-startPos);
            return answer;
        }
    }
};


int main(){
    string num = "9999999999991";
    int k = 8;
    Solution test;
    cout<<test.removeKdigits(num,k)<<endl;
    return 0;
}
