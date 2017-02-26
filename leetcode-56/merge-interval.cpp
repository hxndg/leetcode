#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool comp(const Interval &a,const Interval &b){
    return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0) return intervals;
        vector<Interval> result;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i = 0;i < intervals.size();i++){
            int startPos = intervals[i].start;
            int endPos = intervals[i].end;
            while(i < intervals.size() - 1 && endPos>= intervals[i+1].start){
                i++;
                endPos = max(endPos,intervals[i].end);
            }
            Interval *newInterval = new Interval(startPos,endPos);
            result.push_back(*newInterval);
        }
        return result;
    }
};


int main(){
    Interval *a = new  Interval(1,4);
    Interval *b = new  Interval(2,5);
    vector<Interval> intervals;
    intervals.push_back(*a);
    intervals.push_back(*b);
    Solution test;
    vector<Interval> answer =  test.merge(intervals);
    for(int i=0;i<answer.size();i++){
        cout<<"["<<answer[i].start<< " "<<answer[i].end<<"]";
    }
    return 0;
}
