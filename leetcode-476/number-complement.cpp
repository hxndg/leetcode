#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
      int j = 0,originNum = num;
      while( num > 0){
          num = num >> 1;
          j++;
      }
      long int exclusiveNum = pow(2,j) - 1;
      int result = exclusiveNum ^ originNum;
      cout<<result<<endl;
      return result;
    }
};



int main(){
  int sample = 5;
  Solution test;
  test.findComplement(sample);
  return 0;
}
