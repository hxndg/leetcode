#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0 ; i < n ;i ++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n - i - 1;j++){
                swap(matrix[i][j],matrix[n-j-1][n-i-1]);
            }
        }
    }
};

int main(){
    int line1[3] = {1,2,3};
    int line2[3] = {4,5,6};
    int line3[3] = {7,8,9};
    vector<int> line1V(line1,line1+1);
    vector<int> line2V(line2,line2+2);
    vector<int> line3V(line3,line3+3);
    vector<vector<int>> matrix;
    matrix.push_back(line1V);
    //matrix.push_back(line2V);
    //matrix.push_back(line3V);
    Solution test;
    test.rotate(matrix);
    for(int i = 0 ; i < matrix.size(); i++){
        for(int j = 0 ; j < matrix[i].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
