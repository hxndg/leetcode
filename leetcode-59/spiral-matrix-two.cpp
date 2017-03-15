#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int row = n,col = n;
        vector<vector<int>> result(row,vector<int>(n,0));
        vector<vector<bool>> visited(row,vector<bool>(n,false));
        int i = 0,j = 0,currentNum = 1;
        while(i < row && j < col&& visited[i][j] == false){
            printRound(i,j,visited,result,currentNum);
            i++;
            j++;
        }
        return result;
    }
    void printRound(int row ,int col,vector<vector<bool>> &visited,vector<vector<int>> &result,int &currentNum){
        int m = result.size(),n = result[0].size();
        int i = row,j = col;
        for(;i< m && j < n &&visited[i][j] == false;j++){
            result[i][j] = currentNum;
            visited[i][j] = true;
            currentNum++;
        }
        j--;
        i++;
        for(;i< m && j < n &&visited[i][j] == false;i++){
            result[i][j] = currentNum;
            visited[i][j] = true;
            currentNum++;
        }
        i--;
        j--;
        for(;j >= col && visited[i][j] == false;j--){
            result[i][j] = currentNum;
            visited[i][j] = true;
            currentNum++;
        }
        j++;
        i--;
        for(; i >= row && visited[i][j] == false;i--){
            result[i][j] = currentNum;
            visited[i][j] = true;
            currentNum++;
        }
    }
};

int main(){
    int n = 5;
    Solution test;
    vector<vector<int>> result = test.generateMatrix(n);
    for(int i = 0 ; i < result.size();i ++){
        for(int j = 0 ; j < result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
