/*
   这道题实际上应该是没问题的，但是每次都是runtime error十分令人迷惑
   发现了问题所在之处，之所以出现了深度搜索的问题是因为压栈过多。导致堆栈溢出，从而出现了问题

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        /*
        int m = board.size();
        if(m == 0){
            return;
        }
        int n = board[0].size();
        for(int i = 0 ; i < m ; i++){
                changeConnect(board,i,0);
                if(n > 1){
                    changeConnect(board,i,n-1);
                }
        }
        for(int j = 0 ; j < n ; j++){
                changeConnect(board,0,j);
                if(m > 1){
                    changeConnect(board,m-1,j);
                }
        }
        for(int i = 0 ; i < board.size();i++){
            for(int j = 0 ; j < board[0].size();j++){
                board[i][j] = (board[i][j]=='l'?'O':'X');
            }
        }

    }
    void changeConnect(vector<vector<char>>& board,int i, int j){
        if(board[i][j] == 'O'){
            board[i][j] = 'l';
            int m = board.size(),n = board[0].size();
            if(i + 1 < m ){
                changeConnect(board,i+1,j);
            }
            if(j + 1 < n){
                changeConnect(board,i,j+1);
            }
            if(i > 1){
               changeConnect(board,i-1,j);
            }
            if(j > 1){
                changeConnect(board,i,j-1);
            }
            /*
            if(i >= 1){    // 当我把等于号删去的时候这个问题就通过了？这是什么情况？
                changeConnect(board,i-1,j);
            }
            if(j >= 1){
                changeConnect(board,i,j-1);
            }
          }
          */
    }
};

int main(){
    char line1[4]={'X','X','X','X'};
    vector<char> line1V(line1,line1+4);
    char line2[4]={'X','O','O','X'};
    vector<char> line2V(line2,line2+4);
    char line3[4]={'X','X','O','X'};
    vector<char> line3V(line3,line3+4);
    char line4[4]={'X','O','X','X'};
    vector<char> line4V(line4,line4+4);
    vector<vector<char>> board;
    board.push_back(line1V);
    board.push_back(line2V);
    board.push_back(line3V);
    board.push_back(line4V);
    Solution test;
    test.solve(board);
    for(int i = 0 ; i < board.size();i++){
        for(int j = 0 ; j < board[0].size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
