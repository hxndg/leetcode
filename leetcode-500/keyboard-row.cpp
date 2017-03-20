#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        string line1("qwertyuiop");
        int line1Num = stringToNum(line1);
        string line2("asdfghjkl");
        int line2Num = stringToNum(line2);
        string line3("zxcvbnm");
        int line3Num = stringToNum(line3);
        for(int i = 0 ; i < words.size() ;i ++){
            if(overlap(words[i],line1Num,line2Num,line3Num)){
                result.push_back(words[i]);
            }
        }
        return result;
    }
    int stringToNum(string str){
        int value = 0;
        for(int i = 0 ; i < str.size();i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                str[i] = str[i] + 32;
            }
            int tmp = 1 << (str[i] - 'a');
            value = value | tmp;
        }
        return value;
    }
    bool overlap(string word,int line1,int line2,int line3){
        int wordValue = stringToNum(word);
        bool checkLine1 = (wordValue & line1) == 0;
        bool checkLine2 = (wordValue & line2) == 0;
        bool checkLine3 = (wordValue & line3) == 0;
        if(!checkLine1 && checkLine2 && checkLine3){
            return true;
          }
        if(checkLine1 && !checkLine2 && checkLine3){
            return true;
        }
        if(checkLine1 && checkLine2 && !checkLine3){
            return true;
        }
        return false;
    }
};

int main(){
    string sample[4] = {"Hello","Alaska","Dad","Peace"};
    vector<string> words(sample,sample+4);
    Solution test;
    vector<string> result = test.findWords(words);
    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i]<<" ";
    }
    cout<< endl;
    return 0;
}
