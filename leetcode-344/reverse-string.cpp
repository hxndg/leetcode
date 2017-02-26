/* 这个题没什么好说的，属于基本操作*/

class Solution {
public:
    string reverseString(string s) {
        int end = s.size();
        reverseall(s,0,end-1);
        return s;
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
};
