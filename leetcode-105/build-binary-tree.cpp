
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = buildTree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &preorder,int preStart,int preEnd,vector<int>&inorder,int inStart,int inEnd){
        if(preStart > preEnd || inStart > inEnd){
            return NULL;
        }
        int rootValue = preorder[preStart];
        TreeNode *root = new TreeNode(rootValue);
        int i = inStart;
        for(; i <= inEnd; i++){
            if(inorder[i] == rootValue){
                break;
            }
        }
        root->right = buildTree(preorder,preStart + i - inStart + 1,preEnd,inorder,i + 1,inEnd);
        root->left = buildTree(preorder,preStart + 1,preStart + i - inStart,inorder,inStart,i - 1);
        return root;
    }
};


int main(){
    int in[7] = {1,2,3,5,8,7,9};
    int pre[7] = {5,2,1,3,7,8,9};
    vector<int> inorder(in,in+7);
    vector<int> preorder(pre,pre+7);
    Solution test;
    TreeNode *a = test.buildTree(preorder,inorder);
    return 0;
}
