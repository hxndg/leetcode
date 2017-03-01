/*
  初步感觉是一个深度搜索的问题,然后发现确实是搜索的问题
*/


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;



class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        set<pair<int,int> > hashSet;
        bool answer = false;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[0].size(); j ++){
                if(board[i][j] == word[0]){
                    if(dfs(i,j,board,hashSet,0,word))
                      return true;
                }
            }
        }
        return answer;
    }

    bool dfs(int i,int j,vector<vector<char>>&board,set<pair<int,int>> &hashSet,int index,string word){
        if(index >= word.size()) return true;
        if(i <0 || i >= board.size()) return false;
        if(j <0 || j >= board[0].size()) return false;
        bool answer = false;
        pair<int,int> tmp = make_pair<int,int>(int(i),int(j));
        if(board[i][j] == word[index] && (hashSet.find(tmp) == hashSet.end())){
            pair<set<pair<int,int>>::iterator,bool> insertState =  hashSet.insert(tmp);
            answer = answer || dfs(i+1,j,board,hashSet,index+1,word)||dfs(i-1,j,board,hashSet,index+1,word)||dfs(i,j+1,board,hashSet,index+1,word)||dfs(i,j-1,board,hashSet,index+1,word);
            if(answer == true) return true;
            hashSet.erase(insertState.first);
        }
        return false;
    }
};


int main(){
    char a[4] = {'A','B','C','D'};
    char b[4] = {'S','F','C','S'};
    char c[4] = {'A','D','E','E'};
    vector<char> sampleA(a,a+4);
    vector<char> sampleB(b,b+4);
    vector<char> sampleC(c,c+4);
    vector<vector<char>> board;
    board.push_back(sampleA);
    board.push_back(sampleB);
    board.push_back(sampleC);
    string word("ABCCED");
    Solution test;
    if(test.exist(board,word)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no!"<<endl;
    }
    return 0;
}
