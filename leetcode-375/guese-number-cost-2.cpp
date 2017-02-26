#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
  int getMoneyAmount(int n) {
    vector<int> amt(n+1, 0); // minimum money needed
    vector<int> cnt(n+1, 0); //minimum number of guesses needed

    for(int i=2; i<=n; i++) {
        amt[i] = INT_MAX;
        for(int j=i-1; j>=1; j--) {
            int above = amt[i-j]+j*cnt[i-j]; //money needed to handle [j+1, i]
            int below = amt[j-1]; //money needed to handle [1, j-1]
            if(amt[i]>j+max(above, below)) {
                amt[i] = j+max(above, below);
                cnt[i] = 1 +max(cnt[i-j], cnt[j-1]);
            }
            else if(amt[i]==j+max(above, below)){
                cnt[i] = min(cnt[i], 1+max(cnt[i-j], cnt[j-1])); //prefer lower number to guess
            }
        }
    }
    return amt[n];
}

};


int main(){
    Solution test;
    int n = 1;
    while(n < 21){
        cout<<"n is "<<n<<",cost is "<<test.getMoneyAmount(n)<<endl;
        n++;
    }
    //cout<<"n is 4,cost is "<<test.getMoneyAmount(n)<<endl;

    return 0;
}
