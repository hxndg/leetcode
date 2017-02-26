/*  这个题没什么好说的了，非常直接的解决办法，正常情况都能想到
*/




#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <limits.h>


using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> result;
        for(int i = 0; i< triangle.size();i++){
            vector<int> rowResult(triangle[i].size(),0);
            result.push_back(rowResult);
            for(int j = 0;j < triangle[i].size();j++){
                if(i == 0 && j == 0) {
                    result[i][j] = triangle[0][0];
                }
                if(j == 0 && i != 0){
                    result[i][j] = triangle[i][j] + result[i-1][j];
                }
                if(j == triangle[i].size()-1 && i != 0){
                    result[i][j] = triangle[i][j] + result[i-1][j-1];
                }
                if(j != 0 && j != triangle[i].size()-1){
                    result[i][j] = triangle[i][j] + min(result[i-1][j],result[i-1][j-1]);
                }
            }
        }
        int answer = INT_MAX;
        for(int i = 0;i < triangle[triangle.size()-1].size();i++){
            answer = min(answer,result[triangle.size()-1][i]);
        }
        return answer;
    }
};
