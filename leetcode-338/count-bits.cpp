/*
目前集中的一个问题是，如何将区间话费开，最高位是哪一位如何获得这是当前主要的问题
*/


#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1, 0);
        for(int i = 1;i <= num; ++i){
            result[i] = result[i & (i-1)] + 1;
        }
        return result;
    }
};



int main(){
  int sample = 2;
  Solution test;
  vector<int> answer = test.countBits(sample);
  for(int i =0;i < answer.size();i++){
      cout<< answer[i]<<" ";
  }
  return 0;
}
