/*
   这个题可谓耗时过长，本身头脑不够透彻，问题没有想透甚至想的太乱。
   这道题的想法可以拿去借鉴，每次把底部需要计算的拿去算，然后剩下的为总的，让剩下算的慢慢自己递归去算
*/




#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <queue>

using namespace std;

class Solution {
public:
      string decodeString(string s) {
          string foldedString = s;
          queue< pair<int,int> > bracketQueue;
          queue<int > freqQueue;
          int flat = 0,startPos = 0,endPos = 0;
          for(int i = 0;i<foldedString.size();i++){
              if(foldedString[i] =='[' ){
                  if(flat == 0) startPos = i;
                  flat++;
              }
              if(foldedString[i] == ']'){
                  flat--;
                  if(flat == 0) {
                      endPos = i;
                      freqQueue.push(findNumber(foldedString,startPos));
                      bracketQueue.push(make_pair<int,int>(int(startPos),int(endPos)));
                  }
              }
          }
          string answer;
          for(int i = 0;i<foldedString.size();i++){
              if(foldedString[i] >= '0' && foldedString[i] <= '9'){
                  pair<int,int> tmp = bracketQueue.front();
                  bracketQueue.pop();
                  int freq  = freqQueue.front();
                  freqQueue.pop();
                  string oneString =  decodeString(foldedString.substr(tmp.first+1,tmp.second-tmp.first -1));
                  while(freq > 0){
                      answer = answer + oneString;
                      freq--;
                  }
                  i = tmp.second;
                  continue;
              }
              answer = answer + foldedString[i];
          }
          return answer;
      }
      int findNumber(string s,int startPos){    //这个地方从后往前找比较号，因为从后往前是必然有数字的,startPos是中括号开始的地方
            int endPos = startPos;
            startPos--;
            while(startPos >= 0 && s[startPos] >= '0' && s[startPos] <= '9'){
                startPos--;
            }
            int times = atoi((s.substr(startPos+1,endPos - startPos)).c_str());
            return times;
      }
};


int main(){
    string s("3[a2[c]]hhh");
    Solution test;
    cout<<test.decodeString(s)<<endl;
    return 0;
}
