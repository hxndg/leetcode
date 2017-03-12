#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
       if(prerequisites.size() == 0) return true;
        vector<vector<int>> graph(numCourses,vector<int>());
        for(int i = 0 ; i< prerequisites.size();i++){
            graph[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> visited(numCourses,0);
        bool can = false;
        for(int i = 0 ; i < numCourses;i++){
            set<int> hashSet;
            pair<set<int>::iterator,bool> tmp = hashSet.insert(i);
            if(!dfs(graph,i,hashSet)){
                return false;
            }
            hashSet.erase(tmp.first);
        }
        return true;
    }
    bool dfs(vector<vector<int>> &graph,int index,set<int> &hashSet){
        for(int i = 0 ; i < graph[index].size() ;i ++){
            if(hashSet.find(graph[index][i])!= hashSet.end()){
                return false;
            }
            pair<set<int>::iterator,bool> tmp = hashSet.insert(graph[index][i]);
            if(!dfs(graph,graph[index][i],hashSet)){
                return false;
            }
            hashSet.erase(tmp.first);
        }
        return true;
    }
};


int main(){
    vector<pair<int,int>> prerequisites;
    int n = 2;
    prerequisites.push_back(make_pair<int,int>(1,0));
    prerequisites.push_back(make_pair<int,int>(0,1));
    Solution test;
    cout<<"answer is "<<test.canFinish(n,prerequisites)<<endl;
    return 0;
}
