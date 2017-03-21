/*
    这道题犯了很多错误，包括如何求左右两个树的划分这一块，通过元素个数划分竟然没想起来


*/

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        TreeNode *root = buildTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder,int inStart,int inEnd,vector<int>&postorder,int pStart,int pEnd){
        if(pStart > pEnd || inStart > inEnd){
            return NULL;
        }
        int rootValue = postorder[pEnd];
        TreeNode *root = new TreeNode(rootValue);
        int i = inEnd;
        for(; i >= inStart; i--){
            if(inorder[i] == rootValue){
                break;
            }
        }
        root->right = buildTree(inorder,i+1,inEnd,postorder,pStart + i - inStart,pEnd - 1);
        root->left = buildTree(inorder,inStart,i - 1,postorder,pStart,pStart + i - inStart - 1);
        return root;
    }
};


int main(){
    int in[7] = {1,2,3,5,8,7,9};
    int post[7] = {3,2,1,8,9,7,5};
    vector<int> inorder(in,in+3);
    vector<int> postorder(post,post+3);
    Solution test;
    TreeNode *a = test.buildTree(inorder,postorder);
    return 0;
}
