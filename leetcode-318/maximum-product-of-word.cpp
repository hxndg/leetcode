/*
   两个字符串怎么样来验证有没有相同的字母？这个问题自己的解决方案是香江这个单词的字母，按照字母表的顺序排个序，比较的时候按照归并排序的方法来验证行不行，
   标准答案给出了一种比较巧妙的解决方案，假设用一个0和1组合数字来代表这个单词出现的位数，那么a对应第0位，b对应第1位，c对应第2位，这样子我们从右向左构建起了一个表示字母出现的整数，
   那么两个这样子的整数相互取&，如果答案为零就表示这两个整数没有哪一位同样为1，也就是说这两个整数对应的单词没有哪一位相同，那么就可以计算这两个单词长度的求和
   注释掉的代码是自己原先写的算法，按照标准答案又来了一遍
   下面的链接是标准答案第一个讨论，就是首先提出来这种方法的地方。
   https://discuss.leetcode.com/topic/35539/java-easy-version-to-understand
   下面的链接提出来o(n+N)的方法，这里以每一次提出来的单词所构建出来的value作为索引进行操作,复杂度优化到了
   https://discuss.leetcode.com/topic/31766/bit-shorter-c/2
*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        /*
        int n = words.size();
        for(int i = 0; i < n;i++){
            sort(words[i].begin(),words[i].end());
        }
        vector< vector<bool> > canProduct(n,vector<bool>(n,false));
        int maxProduct = 0;
        for(int i = 0; i < n;i++ ){
            for(int j = i+1; j < n;j++){
                if( !hasSameWord(words[i],words[j])){
                    int product = words[i].size() * words[j].size();
                    maxProduct = max(maxProduct,product);
                }
            }
        }
        return maxProduct;
    }
    bool hasSameWord(string &a, string &b){
        int i = 0,j = 0 ,aSize = a.size(),bSize = b.size();
        while( i < aSize && j < bSize){
            if(a[i] == b[j])
              return true;
            if(a[i] < b[j])
                i++;
            else
                j++;
        }
        return false;
        */

        int n = words.size();
        vector<int> charNumbers(n,0);
        int maxProduct = 0;
        for(int i = 0; i < n;i++){
            string word = words[i];
            int value = 0;
            for(int j = 0;j < word.size();j++){
                value |= 1 << (word[j] - 'a');
            }
            charNumbers[i] = value;
        }
        for(int i = 0; i < n;i++){
            for(int j = i+1; j < n; j++){
                if((charNumbers[i] & charNumbers[j]) != 0) continue;
                int product = words[i].size() * words[j].size();
                maxProduct = max(maxProduct,product);
            }
        }
        return maxProduct;
    }
};


int main(){
    string sample[6] = {"abcw","baz","foo","bar","xtfn","abcdef"};
    vector<string> words(sample,sample+6);
    Solution test;
    cout<<test.maxProduct(words)<<endl;
    return 0;
}
