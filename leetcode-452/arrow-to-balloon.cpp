/*
   从本质上来说，这道题提供了一种对于这种重叠数据的思考，只需要从后面进行考虑，
   对这个问题还是没有理解透
*/

#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

bool comp(pair<int,int> &a,pair<int,int> &b){
    return a.second == b.second ?a.first < b.first:a.second < b.second;
}




class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if(points.size() == 0) return 0;
        sort(points.begin(),points.end(),comp);
        int count = 0, arrow = INT_MIN;
        for(int i = 0; i < points.size();i++){
            if( arrow >= points[i].first){ continue;}
            arrow = points[i].second;
            count ++;
        }
        return count == 0?1:count;
    }
};

int main(){
    vector<pair<int,int>> points;
    points.push_back(pair<int,int>(1,6));
    points.push_back(pair<int,int>(2,8));
    points.push_back(pair<int,int>(7,12));
    points.push_back(pair<int,int>(10,16));
    Solution test;
    cout<<test.findMinArrowShots(points)<<endl;
    return 0;
}
