#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int row = matrix.size();
        if(row == 0){
            return result;
        }
        int col = matrix[0].size();
        vector<vector<bool>> visited(row,vector<bool>(col,false));
        int i = 0,j = 0;
        while(i < row && j < col&& visited[i][j] == false){
            printRound(matrix,i,j,visited,result);
            i++;
            j++;
        }
        return result;
    }
    void printRound(vector<vector<int>> & matrix,int row ,int col,vector<vector<bool>> &visited,vector<int> &result){
        int m = matrix.size(),n = matrix[0].size();
        int i = row,j = col;
        for(;i< m && j < n &&visited[i][j] == false;j++){
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
        j--;
        i++;
        for(;i< m && j < n &&visited[i][j] == false;i++){
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
        i--;
        j--;
        for(;j >= col && visited[i][j] == false;j--){
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
        j++;
        i--;
        for(; i >= row && visited[i][j] == false;i--){
            result.push_back(matrix[i][j]);
            visited[i][j] = true;
        }
    }
};

int main(){
    int row1[3] = {1,2,3};
    int row2[3] = {4,5,6};
    int row3[3] = {7,8,9};
    vector<int> v1(row1,row1+1);
    vector<int> v2(row2,row2+3);
    vector<int> v3(row3,row3+3);
    vector<vector<int>> matrix;
    matrix.push_back(v1);
    //matrix.push_back(v2);
    //matrix.push_back(v3);
    Solution test;
    vector<int> answer = test.spiralOrder(matrix);
    for(int i = 0 ; i < answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
