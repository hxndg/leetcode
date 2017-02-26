#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

struct charFreq{
    int character;
    int frequency;
    charFreq(int a):character(a),frequency(0){}
};

bool comp(const charFreq &a,const charFreq &b){
    return  a.frequency > b.frequency;
}



class Solution {
public:
    string frequencySort(string s) {
        if(s.size() == 0) return s;
        vector<charFreq> result;
        for(int i = 0;i< 256;i++){
            charFreq *tmp = new charFreq(i);
            result.push_back(*tmp);
        }
        for(int i = 0;i<s.size();i++ ){
            result[s[i]].frequency ++;
        }
        sort(result.begin(),result.end(),comp);
        char charString[s.size()];
        int index = 0;
        for(int i = 0;i< 256;i++){
            while(result[i].frequency>0){
                charString[index++] = result[i].character;
                result[i].frequency --;
            }
        }
        string answer(charString,0,s.size());
        return answer;
    }
};


int main(){
    string s("treeeeee");
    Solution test;
    cout<<test.frequencySort(s)<<endl;
    return 0;
}
