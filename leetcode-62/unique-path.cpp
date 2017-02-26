/*
  这个题除了使用动规来做，也可以使用回溯来做，没有注释的代码是回溯，注释掉的代码是动规
  但是呢，动规的做法不超时，很快就能算出来，而回溯的做法就出现了超时的问题，为什么呢？
  举个简答的例子解答，一个3*3的方框，方框最正中心的节点承接着找到从上面的方格到目的地的任务与从左边的方格找到目的地的任务，因此这一个任务他需要运算两次就会导致时间复杂度的增加,那么如果想解决这个问题该怎么做呢？
                 _ _ _
                |_|_|_|
                |_|_|_|
                |_|_|_|
  答案的想法也比较正常，就是倒着找，从最右后方格找回去即可.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct point{
    int x;
    int y;
};

class Solution {
public:
    int uniquePaths(int m, int n) {
      /*
        vector<vector<int>> pathNums(m,vector<int>(n,0));
        for(int i = 0; i< m;i++){
            for(int j = 0; j < n; j++){
                if(i ==0 || j == 0){
                    pathNums[i][j] = 1;
                }
                else{
                    pathNums[i][j] = pathNums[i-1][j] + pathNums[i][j-1];
                }
            }
        }
        return pathNums[m-1][n-1];
    */
        int result=0;
        vector<int> moveOrient;
        point currentPoint;
        currentPoint.x = 1;
        currentPoint.y = 1;
        generatePath(m,n,currentPoint,result);
        return result;
    }

    void generatePath(int m, int n ,point currentPoint,int & result){
        if(currentPoint.x == m && currentPoint.y == n ){
            result++;
            return;
        }
        point nextPoint;
        if(currentPoint.y == n ){
            nextPoint.x = currentPoint.x + 1;
            nextPoint.y = currentPoint.y;
            generatePath(m,n,nextPoint,result);
        }
        if(currentPoint.x == m){
            nextPoint.x = currentPoint.x;
            nextPoint.y = currentPoint.y + 1;
            generatePath(m,n,nextPoint,result);
        }
        if((currentPoint.x != m) && ( currentPoint.y != n)){
            nextPoint.x = currentPoint.x + 1;
            nextPoint.y = currentPoint.y;
            generatePath(m,n,nextPoint,result);
            nextPoint.x = currentPoint.x;
            nextPoint.y = currentPoint.y + 1;
            generatePath(m,n,nextPoint,result);
        }
    }
};

int main(){
    int m = 3, n =3;
    Solution test;
    cout<<"answer is "<<test.uniquePaths(m,n)<<endl;
    return 0;
}
