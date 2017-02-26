/*
   好吧，这道题要求的in-place 算法竟然可以通过位操作。。这一点是我没有想到的，的确32位整数可以存储冗余信息31个，
   这一点确实很有意思
*/


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
         int m = board.size(),n = board[0].size();
         for(int i = 0 ; i < m ; i ++){
             for(int j = 0 ; j < n ; j ++){
                 int count = 0;
                 for(int x = i-1; x <= i+1;x++){
                     for(int y = j -1; y <= j+1;y++){
                         if(x < 0 || x > m-1) continue;
                         if(y < 0 || y > n-1) continue;
                         if(x == i && y == j) continue;
                         count = count + (board[x][y]&1);
                     }
                 }
                 board[i][j] = canLive(count,board[i][j]);
             }
         }
         for(int i = 0 ; i < m; i++){
             for(int j = 0 ;j < n; j++){
                 board[i][j] = board[i][j] >> 1;
             }
         }
         return;
    }

    int canLive(int count,int originValue){
        if((count < 2) || (count > 3 && ((originValue & 1) == 1))){
            return originValue;
        }
        if((count == 3) && ((originValue & 1 )== 0)){
            return originValue|2;
        }
        if((count == 2||count == 3) && ((originValue & 1)== 1)){
            return  originValue|2;
        }
        return 0;
    }
};

int main(){
    int sampleA[2] = {1,1};
    int sampleB[2] = {1,0};
    vector<int> a(sampleA,sampleA+2);
    vector<int> b(sampleB,sampleB+2);
    vector<vector<int>> board;
    board.push_back(a);
//    board.push_back(b);
    Solution test;
     test.gameOfLife(board);
    for(int i = 0 ; i< board.size();i++){
        for(int j = 0; j< board[i].size();j++){
             cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0 ;
}
