#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;


class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long int sumAll = 0,length = A.size();
        for(long int i = 0; i < length; i++){
            sumAll += A[i];
        }
        vector<long int> gain(length,0);
        for(long int i = 1; i < length; i++){
            gain[i] = sumAll - length*A[length - i];
        }
        long int originSum = 0;
        for(long int i = 0;i<length;i++){
            originSum += i*A[i];
        }
        long int maxGain = 0;
        for(long int i = 1;i<length;i++){
            gain[i] = gain[i] + gain[i-1];
            maxGain = max(maxGain,gain[i]);
        }
        return originSum+maxGain;
    }
};

int main(){
    int sample[10] = {1,2,3,4,5,6,7,8,9,10};
    vector<int> A(sample,sample+10);
    Solution test;
    cout<<test.maxRotateFunction(A)<<endl;
    return 0;
}
