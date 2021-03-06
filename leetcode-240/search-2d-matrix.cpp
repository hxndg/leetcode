/*
    没有找到能够继续缩减时间的方法，本身只能从上向下搜索
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        int i = 0 , j = col - 1;
        while(i < row && j >= 0){
            if(matrix[i][j] == target){
                return true;
            }
            else{
                if(matrix[i][j] < target){
                    i++;
                }
                else{
                    j--;
                }
            }
        }
        return false;
      }
};
