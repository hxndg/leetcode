/* 没什么特别要注意的东西，就是一个简单的范围计算
*/




#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int durationAll = 0,durationOnce = 0,maxEndTime = 0;
        for(int i = 0;i < timeSeries.size();i++){
            durationOnce = timeSeries[i] + duration - max(maxEndTime,timeSeries[i]);
            durationAll += durationOnce;
            maxEndTime = timeSeries[i] + duration;
        }
        return durationAll;
    }
};

int main(){
    int sample[4] = {1,2,3,4};
    int duration = 2;
    vector<int> timeSeries(sample,sample+4);
    Solution test;
    cout << test.findPoisonedDuration(timeSeries,duration)<<endl;
    return 0;
}
