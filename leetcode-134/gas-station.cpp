/*
    这道题实际上让我想起来原先做过的乘水最多的容器，问题同样是两端才能决定具体能不能承够足够的水，
    但是为什么时间复杂度能做到o(n)级别？而为什么最直接的解法时间复杂度是o(n^2)的时间呢？
    标准答案的解法是双边延伸的，而原先那道题是双向缩小的
    这种做法的巧妙之处在哪里？实际上我们根本不关心具体的起点，我们只需要单向延伸，如果碰到我们想要的就直接延伸到头
    如果没有碰到那么我们向两边的延伸过程必然会遇到我们的起点
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
         vector<int> lefted;
         for(int i = 0 ; i < gas.size(); i++){
             lefted.push_back(gas[i] - cost[i]);
         }
          int end = 0,start = lefted.size()-1,sum = lefted[start];
          while(start > end){
              if(sum >= 0){
                  sum += lefted[end];
                  ++end;
              }
              else{
                  start--;
                  sum += lefted[start];
              }
          }
          return sum >=0?start:-1;
    }

};

int main(){
    int sample[2] = {1,1};
    vector<int> gas(sample,sample+2);
    vector<int> cost(sample,sample+2);
    Solution test;
    cout<<"Start Point is "<<test.canCompleteCircuit(gas,cost)<<endl;
    return 0;
}
