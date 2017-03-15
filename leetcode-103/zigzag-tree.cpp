/*
   levelOrder的简单变形，原本都是正的顺序，现在把一部分的顺序换成了逆序
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result = levelOrder(root);
        for(int i = 0 ; i < result.size(); i++){
            if( (i + 1) % 2 == 0){
                reverse(result[i].begin(),result[i].end());
            }
        }
        return result;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if( root == NULL){
            return result;
        }
        vector<vector<int>> rightLevel = levelOrder(root->right);
        vector<vector<int>> leftLevel = levelOrder(root->left);
        result.push_back(vector<int>(1,root->val));
        int leftSize = leftLevel.size(),rightSize = rightLevel.size(),minLevel = min(leftSize,rightSize),i = 0;
        for(i = 0 ; i < minLevel;i++){
            vector<int> add;
            add.insert(add.end(),leftLevel[i].begin(),leftLevel[i].end());
            add.insert(add.end(),rightLevel[i].begin(),rightLevel[i].end());
            result.push_back(add);
        }
        if( leftLevel.size() > minLevel){
            while(i < leftLevel.size()){
                result.push_back(leftLevel[i]);
                i++;
            }
        }
        if( rightLevel.size() > minLevel){
            while(i < rightLevel.size()){
                result.push_back(rightLevel[i]);
                i++;
            }
        }
        return result;
     }
};


int main(){
    TreeNode *a = new TreeNode(3);
    TreeNode *b = new TreeNode(9);
    TreeNode *c = new TreeNode(20);
    TreeNode *d = new TreeNode(15);
    TreeNode *e = new TreeNode(7);
    a->left = b;a->right = c;
    c->left = d;c->right = e;
    Solution test;
    vector<vector<int>> answer = test.zigzagLevelOrder(a);
    for(int i = 0 ; i < answer.size(); i++){
        for(int j = 0 ;j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
