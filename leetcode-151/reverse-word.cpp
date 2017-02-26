#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Solution {
public:
    void reverseWords(string &s) {
        eraseSpace(s);
        reverseall(s,0,s.size() -1);
        for(int i = 0;i<s.size();i++){
            if(s[i]== ' ') continue;
            int startPos = i;
            while(s[i] != ' ' && i<s.size()){
                i++;
            }
            int endPos = i-1;
            reverseall(s,startPos,endPos);
        }
        eraseSpace(s);
        eliminateExtraSpace(s);
    }
    void reverseall(string &s,int i,int j){       //给定字符串，逆转i到j位置的字符
        char tmp;
        while( i <= j){
            tmp = s[j];
            s[j] = s[i];
            s[i] = tmp;
            i++;
            j--;
        }
    }
    void eraseSpace(string &s){                 //去除开始的空格
        int i = 0;
        for(i = 0;i<s.size();i++){
            if( s[i] !=' '){
                break;
            }
        }
        s.erase(0,i);
    }
    void eliminateExtraSpace(string &s){      //去除中间的空格
      int spaceStartPos = 0, spaceLength = 0;
      for(int i = 0 ; i< s.size(); i++){
          if(s[i] == ' '){
              spaceStartPos = i;
              while(s[i] == ' '){
                  i++;
              }
              spaceLength = i - spaceStartPos - 1;
              s.erase(spaceStartPos,spaceLength); // 这里犯了一个愚蠢的错误，当删除掉一部分元素时，i的值应当跟着减少，但是这里i没做任何运算因此出现了问题。
              i = i - spaceLength;
          }
      }
      return;
    }
};


int main(){
    string s = "   a   b  c d   e  ";
    Solution test;
    test.reverseWords(s);
    cout<< s<<"end"<<endl;
    return 0;
}
