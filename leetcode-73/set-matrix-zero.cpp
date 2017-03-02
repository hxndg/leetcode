#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int firstColumn = 1;
        for(int i = 0 ; i < matrix.size(); i ++){
            if(matrix[i][0] == 0) {
                firstColumn = 0;
            }
            for(int j = 1 ; j < matrix[0].size(); j ++){
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1 ; i < matrix.size();i++){
            for(int j = 1 ; j < matrix[0].size(); j ++){
                if(matrix[i][0] == 0 || matrix[0][j] == 0){
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0){
            for(int i = 0 ; i < matrix[0].size();i++){
                matrix[0][i] = 0;
            }
        }
        if(firstColumn == 0){
            for(int i = 0 ; i < matrix.size();i++){
                matrix[i][0] = 0;
            }
        }

    }
};


int main(){
    int a[4] = {0,1,0,3};
    int b[4] = {2,1,0,3};
    int c[4] = {0,1,2,3};
    int d[4] = {9,1,2,3};
    int e[4] = {9,1,3,0};
    vector<int> tmpA(a,a+4);
    vector<int> tmpB(b,b+4);
    vector<int> tmpC(c,c+4);
    vector<int> tmpD(d,d+4);
    vector<int> tmpE(e,e+4);
    vector<vector<int>> matrix;
    matrix.push_back(tmpA);
    matrix.push_back(tmpB);
    matrix.push_back(tmpC);
    matrix.push_back(tmpD);
    matrix.push_back(tmpE);

    Solution test;
    test.setZeroes(matrix);
    for(int i = 0 ; i < matrix.size();i++){
        for(int j = 0 ; j < matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;

}
