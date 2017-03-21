/*
    方法是dfs深度优先搜索方法，那么如果使用bfs的方法行不行呢？


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int  m = grid.size();
        if(m == 0){
            return 0;
        }
        int n = grid[0].size();
        vector<vector<bool>>  visited(m,vector<bool>(n,false));
        int islandCount = 0;
        for(int i = 0 ; i < m ; i ++){
            for(int j = 0 ; j < n ; j ++){
                if(visited[i][j] == true){
                    continue;
                }
                if(grid[i][j] == '1'){
                    islandCount ++;
                    checkIsland(grid,visited,i,j);
                }
                visited[i][j] = true;
            }
        }
        return islandCount;
    }
    void checkIsland(vector<vector<char>>&grid,vector<vector<bool>>&visited,int i ,int j){
        visited[i][j]= true;
        if(i+1 < grid.size() && grid[i+1][j] == '1' && visited[i+1][j] == false) {
            checkIsland(grid,visited,i+1,j);
        }
        if(j+1 < grid[0].size() && grid[i][j+1] == '1'&& visited[i][j+1] == false){
            checkIsland(grid,visited,i,j+1);
        }
        if(i-1 >= 0 && grid[i-1][j] == '1'&& visited[i-1][j] == false){
            checkIsland(grid,visited,i-1,j);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1'&& visited[i][j-1] == false){
            checkIsland(grid,visited,i,j-1);
        }
        return;
    }
};


int main(){
    char line1[5] = {'1','1','1','0','0'};
    char line2[5] = {'0','1','0','0','0'};
    char line3[5] = {'1','1','1','0','0'};
    char line4[5] = {'0','0','0','1','1'};
    vector<char> line1V(line1,line1+3);
    vector<char> line2V(line2,line2+3);
    vector<char> line3V(line3,line3+3);
    vector<char> line4V(line4,line4+5);
    vector<vector<char>> grid;
    grid.push_back(line1V);
    grid.push_back(line2V);
    grid.push_back(line3V);
    //grid.push_back(line4V);
    Solution test;
    cout<<"answer is "<<test.numIslands(grid)<<endl;
    return 0;
}
