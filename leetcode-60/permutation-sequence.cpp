#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> result;
        vector<int> candidates;
        int factorial = 1;
        for(int i = 0; i < n; i++){
            candidates.push_back(i+1);
        }
        for(int i = 0 ;i < n-1;i++){
            factorial = factorial * (i+1);
        }
        generatePermutation(candidates,result,k-1,factorial);
        string answer;
        for(int i = 0 ;i < result.size();i++){
            answer += to_string(result[i]);
        }
        return answer;
    }
    void generatePermutation(vector<int> &candidates,vector<int> &result,int k,int factorial){ //需要注意这里是小一号的阶乘，比方说当前处理的是n个数，那么这个算出来的(n-1)!，不是n的阶乘
        int n = candidates.size();
        if( n == 1) {
            result.push_back(candidates[0]) ;
            return ;
        }
        int sumFactorial = 0;
        while(sumFactorial+factorial <= k){
            sumFactorial += factorial;
        }
        int headNum = sumFactorial/factorial;
        result.push_back(candidates[headNum]);
        vector<int> tmpCandidates(candidates.begin(),candidates.end());
        tmpCandidates.erase(tmpCandidates.begin()+headNum);//在这里写的时候出现了一个bug，一开始写得是candidates，由于有写时复制的特性，因此tmpCandidates也被改写了，但是因为candidates被改写导致result的结果就出现了错误
        generatePermutation(tmpCandidates,result,k-sumFactorial,factorial/(n-1));
    }
};

int main(){
    int n = 3, k = 1;
    Solution test;
    while(k <= 6){
        cout<<test.getPermutation(n,k)<<endl;
        k++;
    }
    return 0;
}
