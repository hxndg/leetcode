#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits == ""){
            vector<string> result;
            return result;
        }
        char lastChar = digits[digits.size() - 1];
        vector<char> backUpChar = getBackUpChar(lastChar);
        vector<string> result;
        if(digits.size() == 1){
            for(int j = 0 ; j < backUpChar.size() ; j++){
                string tmp;
                tmp += backUpChar[j];
                result.push_back(tmp);
            }
            return result;
        }
        string preDigits(digits.begin(),digits.begin()+digits.size()-1);
        vector<string> preResult = letterCombinations(preDigits);
        for(int i = 0 ; i < preResult.size();i++){
            for(int j = 0 ; j < backUpChar.size() ; j++){
                result.push_back(preResult[i]+backUpChar[j]);
            }
        }
        return result;
    }

    vector<char> getBackUpChar(char c){
      int number = c - '0';
      vector<char> backUpChar;
      if( number <= 6){
          int index = (number-2)*3;
          backUpChar.push_back('a'+ index );
          backUpChar.push_back('a' + index + 1);
          backUpChar.push_back('a' + index + 2);
      }
      if( number == 7){
          backUpChar.push_back('p');
          backUpChar.push_back('q');
          backUpChar.push_back('r');
          backUpChar.push_back('s');
      }
      if( number == 8){
          backUpChar.push_back('t');
          backUpChar.push_back('u');
          backUpChar.push_back('v');
      }
      if( number == 9 ){
          backUpChar.push_back('w');
          backUpChar.push_back('x');
          backUpChar.push_back('y');
          backUpChar.push_back('z');
      }
      return backUpChar;
    }
};


int main(){
    string digits("23");
    Solution test;
    vector<string> answer = test.letterCombinations(digits);
    for(int i = 0; i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
