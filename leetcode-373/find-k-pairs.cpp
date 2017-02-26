/*
   优先队列，巧妙的解法，非常值得一记，而且需要知道优先队列里比较符号是true的话，排列顺序就是false
   还需要记住，优先队列比较符的声明定义方式，需要定义一个类，然后修改括号
   如果操作的对象是结构体，最好在结构体内进行修改，这样子能够直接操作
   总而言之这道题是一个很不错的题，值得记住
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;

class addValue{
public:
    int row,col,val;
    addValue(int a,int b,int c):row(a),col(b),val(c){}
};

bool operator > (const addValue &a,const addValue &b){
    return a.val > b.val;
}

class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(),n = nums2.size();
        vector<pair<int,int>> result;
        if(m == 0 || n== 0) return result;
        priority_queue<addValue,vector<addValue>,greater<addValue> > pq;
        for(int i = 0; i < nums2.size();i++){
            int value = nums1[0] + nums2[i];
            addValue *tmp = new addValue(i,0,value);
            pq.push(*tmp);
        }
        int target = min(k,m*n);
        while(target >0 && !pq.empty()){
            addValue tmp = pq.top();
            pq.pop();
            result.push_back(make_pair<int,int>(int(nums1[tmp.col]),int(nums2[tmp.row])));
            target --;
            if(tmp.col == m-1){ continue;}
            int value = nums1[tmp.col+1]+nums2[tmp.row];
            addValue *newOne = new addValue(tmp.row,tmp.col+1,value);
            pq.push(*newOne);

        }
        return result;
    }
};


int main(){
    int a[3] = {1,4,7};
    int b[3] = {2,4,6};
    vector<int> nums1(a,a+3);
    vector<int> nums2(b,b+3);
    Solution test;
    test.kSmallestPairs(nums1,nums2,2);
    return 0;
}
