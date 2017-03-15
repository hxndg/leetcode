/*
   bad bad answer ,时间复杂度太高了


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0){
            return 0;
        }
        int n = matrix[0].size();
        int maxLength = max(m,n);
        vector<vector<vector<bool>>> square(maxLength,vector<vector<bool>>(m + 1,vector<bool>(n + 1,false)));
        int maxSide = 0;
        for(int k = 0 ; k < maxLength;k++){
            for(int i = 1 ; i < square[k].size(); i++){
                for(int j = 1 ; j < square[k][i].size() ;j ++){
                    if(k == 0){
                        if(matrix[i-1][j-1] == '1'){
                            square[k][i][j] = true;
                            maxSide = 1;
                        }
                    }
                    else{
                        if(i + k > m || j + k > n){
                            continue;
                        }
                        else{
                            if( square[k-1][i][j] && square[k-1][i+1][j] && square[k-1][i+1][j+1] && square[k-1][i][j+1]){
                                square[k][i][j] = true;
                                maxSide = max(maxSide,k+1);
                            }
                        }
                    }
                }
            }
        }
        return maxSide*maxSide;
    }
};

int main(){
    char line1[8] = {'1','1','1','1','1','1','1','1'};
    char line2[8] = {'1','1','1','1','1','1','1','0'};
    char line3[8] = {'1','1','1','1','1','1','1','0'};
    char line4[8] = {'1','1','1','1','1','0','0','0'};
    char line5[8] = {'0','1','1','1','1','0','0','0'};
    vector<char> line1V(line1,line1+8);
    vector<char> line2V(line2,line2+8);
    vector<char> line3V(line3,line3+8);
    vector<char> line4V(line4,line4+8);
    vector<char> line5V(line5,line5+8);
    vector<vector<char>> matrix;
    matrix.push_back(line1V);
    matrix.push_back(line2V);
    matrix.push_back(line3V);
    matrix.push_back(line4V);
    matrix.push_back(line5V);
    Solution test;
    cout<<" answer is "<<test.maximalSquare(matrix)<<endl;
    return 0;
}
