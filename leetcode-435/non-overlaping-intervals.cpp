/*
   贪心的引用，这个题需要记住，还不是很理解
*/


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool mycomp(Interval &a,Interval &b){
    return a.end == b.end ? a.start < b.start:a.end < b.end;
}

class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),mycomp);
        int count = 0,bounds = INT_MIN;
        for(int i = 0 ; i < intervals.size();i++){
            if(bounds > intervals[i].start){
                count ++;
            }
            else{
               bounds = intervals[i].end;
            }
        }
        return count;
    }
};


int main(){
    Interval *a = new Interval(1,2);
    Interval *b = new Interval(2,3);
    Interval *c = new Interval(3,4);
    Interval *d = new Interval(1,3);
    vector<Interval> intervals;
    intervals.push_back(*a);
    intervals.push_back(*b);
    intervals.push_back(*c);
    intervals.push_back(*d);
    Solution test;
    cout<<"minimum eliminate is "<< test.eraseOverlapIntervals(intervals)<<endl;
    return 0;
}
