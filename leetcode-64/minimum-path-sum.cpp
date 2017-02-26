/*
    基本的动规，不需要说太多
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int> > answerGrid(row,vector<int>(col,0));
        for(int i = 0 ; i < row; i++){
            for(int j = 0 ;j < col; j++){
                if(i == 0 && j == 0){
                    answerGrid[i][j] = grid[i][j];
                }
                if(i == 0 && j != 0){
                    answerGrid[i][j] = answerGrid[i][j-1] + grid[i][j];
                }
                if(j == 0 && i != 0){
                    answerGrid[i][j] = answerGrid[i-1][j] + grid[i][j];
                }
                if( j != 0 && i != 0){
                    answerGrid[i][j] = min(answerGrid[i-1][j],answerGrid[i][j-1]) + grid[i][j];
                }
            }
        }
        return answerGrid[row-1][col-1];
    }
};

int main(){
    vector< vector<int> > grid;
    int sample0[3] = {1,2,3};
    int sample1[3] = {4,5,6};
    int sample2[3] = {7,8,9};
    vector<int> a(sample0,sample0+3);
    vector<int> b(sample1,sample1+3);
    vector<int> c(sample2,sample2+3);
    grid.push_back(a);
    grid.push_back(b);
    grid.push_back(c);
    Solution test;
    cout<<"answer is "<<test.minPathSum(grid)<<endl;
    return 0;
}
