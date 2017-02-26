/*
这道题并不难，但是确实比较容易乱，对于应该取哪一个起始坐标那里烦了很大的错误。需要注意，值得一记
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int i = 0,j = 0,m = matrix.size();
        vector<int> result;
        if(m == 0) return result;
        int n = matrix[0].size(),k=0; //m是行，n是列
        bool orient = true;
        if(m == 1) return matrix[0];
        if(n == 1) {
            for(i = 0;i<matrix.size();i++){
                result.push_back(matrix[i][0]);
            }
            return result;
        }
        while(k <= m+n-2){
            if(orient == true) {
                i = k;
                j = 0;
                while(i > m-1){i--;j++;}
                while(i >=0 && i <= m-1 && j >=0 && j<= n-1){
                    cout<<matrix[i][j];
                    result.push_back(matrix[i--][j++]);
                }
                k++;
                orient = false;
            }
            else{
                j = k;
                i = 0 ;
                while(j > n-1){j--;i++;}
                while(i >=0 && i <= m-1 && j >=0 && j<= n-1){
                    cout<<matrix[i][j];
                    result.push_back(matrix[i++][j--]);
                }
                k++;
                orient = true;
            }
        }
        return result;
    }
};

int main(){
    int line1[3] = {1,2,3};
    vector<int> line1V(line1,line1+3);
    int line2[3] = {4,5,6};
    vector<int> line2V(line2,line2+3);
    int line3[3] = {7,8,9};
    vector<int> line3V(line3,line3+3);
    vector<vector<int>> matrix;
    matrix.push_back(line1V);
    matrix.push_back(line2V);
    matrix.push_back(line3V);
    Solution test;
    test.findDiagonalOrder(matrix);
    return 0;
}
