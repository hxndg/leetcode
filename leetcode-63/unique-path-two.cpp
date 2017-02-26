#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size(),col = obstacleGrid[0].size();
        vector<vector<int>> answerGrid(row,vector<int>(col,1));
        for(int i = 0; i < row; i ++){
            for(int j = 0; j < col; j++){
                if(i == 0 && j ==0){
                    if(obstacleGrid[i][j] == 1){
                        return 0;
                    }
                    answerGrid[i][j] = 1;
                }
                if(i == 0 && j != 0){
                    if(obstacleGrid[i][j] == 1){
                        answerGrid[i][j] = 0;
                    }
                    else{
                        answerGrid[i][j] = answerGrid[i][j-1];
                    }
                }
                if( i != 0 && j == 0){
                    if(obstacleGrid[i][j] == 1){
                        answerGrid[i][j] = 0;
                    }
                    else{
                        answerGrid[i][j] = answerGrid[i-1][j];
                    }
                }
                if( i != 0 && j != 0){
                    if(obstacleGrid[i][j] == 1){
                        answerGrid[i][j] = 0;
                    }
                    else{
                        answerGrid[i][j] = answerGrid[i][j-1] + answerGrid[i-1][j];
                    }
                }
            }
        }
        return answerGrid[row - 1][col - 1];
    }
};


int main(){
    vector< vector<int> > obstacleGrid;
    int sample0[3] = {0,0,0};
    int sample1[3] = {0,1,0};
    int sample2[3] = {0,0,0};
    vector<int> a(sample0,sample0+3);
    vector<int> b(sample1,sample1+3);
    vector<int> c(sample2,sample2+3);
    obstacleGrid.push_back(a);
    obstacleGrid.push_back(b);
    obstacleGrid.push_back(c);
    Solution test;
    cout<<" answer is "<<test.uniquePathsWithObstacles(obstacleGrid)<<endl;
    return 0;
}
