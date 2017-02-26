/* 非常有意思的一道题，想的角度很奇特，数战舰的个数只需要数战舰的头就行
   而战舰的要么从上到下，要么从左到右，因此判断战舰的头只需要看这个节点相邻的地方有没有及诶单即可
   蛮有意思的
*/




class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(board.empty() || board[0].empty()) return 0;
        int column = board.size();
        int row = board[0].size();
        int count = 0;
        for(int i = 0; i < column;i++){
          for(int j = 0; j < row;j++){
              if( i>0 && j>0 && board[i - 1][j]!='X' && board[i][j-1] != 'X' && board[i][j] =='X'){
                  count++;
              }
              if(j == 0 && i!=0 && board[i-1][j]!='X' && board[i][j] =='X'){
                  count++;
              }
              if(i == 0 && j!=0 && board[i][j-1]!= 'X' && board[i][j] == 'X'){
                  count++;
              }
              if(i==0 && j==0 && board[i][j]=='X'){
                  count++;
              }
          }
        }
        return count;
    }
};
