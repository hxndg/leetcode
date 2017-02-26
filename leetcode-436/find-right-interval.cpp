/*
   这道题的启示是什么？
   有很多点
   1 不一定非得构造结构来存储某个元素和index，可以利用map来构建键值对存储
   2 这个题目没有特别好的做法吗？本质上来说是存储键值对，然后找到一个比它小的就把它存起来，
   3 这道题提供了一个map（！！）的lower_bound方法，这个方法可以很方便的找到第一个比某个key值大的元素，这种排序方法很不错


*/

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>

using namespace std;
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        vector<int> result;
        map<int,int> hashMap;
        for(int i = 0 ; i < intervals.size();i++){
            hashMap.insert(make_pair<int,int>(int(intervals[i].start),int(i)));
        }
        for(int i = 0 ; i < intervals.size();i++){
            map<int,int>::iterator iter = hashMap.lower_bound(intervals[i].end);
            if(iter == hashMap.end()){
                result.push_back(-1);
            }
            else{
                result.push_back(iter->second);
            }
        }
        return result;
    }
};

int main(){
    Interval *a = new Interval(1,4);
    Interval *b = new Interval(2,3);
    Interval *c = new Interval(3,4);
    vector<Interval> intervals;
    intervals.push_back(*a);
    intervals.push_back(*b);
    intervals.push_back(*c);
    Solution test;
    vector<int> answer = test.findRightInterval(intervals);
    for(int i = 0 ; i < answer.size() ; i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;

}
