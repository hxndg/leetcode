#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(),n = matrix[0].size();
        queue<pair<int,int>> dealQueue;
        vector<vector<int>> result(m,vector<int>(n,INT_MAX));
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(matrix[i][j] == 0){
                    dealQueue.push(make_pair<int,int>(int(i),int(j)));
                }
            }
        }
        int dealCount = 0,totalCount = (m+1)*(n+1);
        while(!dealQueue.empty()){
           pair<int,int> target = dealQueue.front();
           dealQueue.pop();
           int i = target.first,j = target.second;
           if(matrix[i][j] == 0){
               result[i][j] = 0;
           }
           else{
               int minDistance = INT_MAX;
               if(i > 0){
                   minDistance = min(result[i-1][j],minDistance);
               }
               if(i < m-1){
                   minDistance = min(minDistance,result[i+1][j]);
               }
               if(j > 0){
                   minDistance = min(minDistance,result[i][j-1]);
               }
               if(j < n-1){
                   minDistance = min(minDistance,result[i][j+1]);
               }
               result[i][j] = minDistance + 1;
           }
           if(i > 0 && result[i-1][j] == INT_MAX){
               dealQueue.push(make_pair<int,int>(int(i-1),int(j)));
           }
           if(i < m-1 && result[i+1][j] == INT_MAX){
               dealQueue.push(make_pair<int,int>(int(i+1),int(j)));
           }
           if(j > 0 && result[i][j-1] == INT_MAX){
               dealQueue.push(make_pair<int,int>(int(i),int(j-1)));
           }
           if(j < n-1 && result[i][j+1] == INT_MAX){
               dealQueue.push(make_pair<int,int>(int(i),int(j+1)));
           }
        }
        return result;
    }
};

int main(){
    int line1[3] = {0,0,0};
    int line2[3] = {0,1,0};
    int line3[3] = {1,1,1};
    vector<int> line1V(line1,line1+3);
    vector<int> line2V(line2,line2+3);
    vector<int> line3V(line3,line3+3);
    vector<vector<int>> matrix;
    matrix.push_back(line1V);
    matrix.push_back(line2V);
    matrix.push_back(line3V);
    Solution test;
    vector<vector<int>> answer  = test.updateMatrix(matrix);
    for(int i = 0 ; i < answer.size(); i++){
        for(int j = 0 ; j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
