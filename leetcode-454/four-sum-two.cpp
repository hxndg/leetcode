/*
  没什么好说的，就是简答的hash表应用，复杂度到了n^2的级别，还不算很糟糕

*/



#include <iostream>
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int,int>  hashMap;
        int length = A.size();
        for(int i = 0; i < length;i++){
            for(int j = 0;j < length;j++){
                int sum = A[i] + B[j];
                map<int,int>::iterator iter = hashMap.find(sum);
                if(iter == hashMap.end()){
                    hashMap.insert(make_pair<int,int>(int(sum),1));
                }
                else{
                    iter->second++;
                }
            }
        }
        int count = 0;
        for(int i = 0;i<length;i++){
            for(int j = 0;j < length; j++){
                int sum = C[i] + D[j];
                map<int,int>::iterator iter = hashMap.find(-1*sum);
                if(iter != hashMap.end()){
                    count += iter->second;
                }
            }
        }
        return count;
    }
};


int main(){
    int a[2] = {-1,-1};
    int b[2] = {-1,1};
    int c[2] = {-1,1};
    int d[2] = {1,-1};
    vector<int> A(a,a+2);
    vector<int> B(b,b+2);
    vector<int> C(c,c+2);
    vector<int> D(d,d+2);
    Solution test;
    cout<<test.fourSumCount(A,B,C,D)<<endl;
    return 0;
}
