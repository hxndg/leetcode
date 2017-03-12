#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool comp(const int &a, const int &b){
    return a>b;
}


class Solution {
public:
    int hIndex(vector<int>& citations) {
        if(citations.size() == 0) return 0;
        sort(citations.begin(),citations.end());
        int n = citations.size(),hIndexNum = 0;
        for(int i = 0 ; i < citations.size() ; i ++){
            if(citations[i] >= n - i){
                hIndexNum = max(hIndexNum,n - i);
            }
        }
        return hIndexNum;
    }
};

int main(){
    int a[5] = {100,0,6,1,5};
    vector<int> citations(a,a+1);
    Solution test;
    cout<<"answer is "<<test.hIndex(citations)<<endl;
    return 0;
}
