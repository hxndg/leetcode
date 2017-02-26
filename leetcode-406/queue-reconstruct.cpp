/* 这个题改一个名字可以叫做论插入方式，就是这种巧妙的插入方式使得运算大为简单，是一种很不错的想法。 
*/



#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool comp(const pair<int,int> &a,const pair<int,int> &b){
    return (a.first > b.first || (a.first == b.first && a.second < b.second));
}

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(),comp);
        vector< pair<int,int> > result;
        for(int i = 0;i< people.size(); i++){
            result.insert(result.begin()+people[i].second,people[i]);
        }
        return result;
    }
};
