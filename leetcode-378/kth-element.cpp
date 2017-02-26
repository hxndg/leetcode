/*
   讲道理这种方法并不好，应当使用二分的方法效果会比较好

*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int row = matrix.size(),col = row;
        vector<int> sortedArray;
        vector<int> preArray = matrix[0];
        for(int i = 1;i < row;i++){
            int j = 0,k = 0;
            while(j < preArray.size() && k < matrix[i].size()){
                if( preArray[j] <= matrix[i][k]){
                    sortedArray.push_back(preArray[j++]);
                }
                else{
                    sortedArray.push_back(matrix[i][k++]);
                }
            }
            while( j < preArray.size()){
                sortedArray.push_back(preArray[j++]);
            }
            while( k < matrix[i].size()){
                sortedArray.push_back(matrix[i][k++]);
            }
            preArray.swap(sortedArray);
            sortedArray.clear();
        }
        return preArray[k-1];
    }
};


int main(){
    int a[2] = {1,4};
    int b[2] = {2,5};
    //int c[3] = {12,13,15};
    vector<int> aV(a,a+2);
    vector<int> bV(b,b+2);
    //vector<int> cV(c,c+3);
    vector<vector<int>> matrix;
    matrix.push_back(aV);
    matrix.push_back(bV);
    //matrix.push_back(cV);
    Solution test;
    cout<<test.kthSmallest(matrix,1)<<endl;
    return 0;
}
