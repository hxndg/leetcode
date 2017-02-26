/*
    你这个方法太复杂了。。。。
    中序遍历bst会得到一个递增的数列，
    因此只需要中序遍历并且看这个值是不是递增的就可以。。。
    利用morris遍历方法能够很方便的解这道题。。。。
*/



#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        int i = 0,j = 0;
        return isValidBst(root,i,j);
    }
    bool isValidBst(TreeNode* root,int &smallestOne,int &biggestOne){
        int rightSmallest = 0,rightBiggest = 0,leftSmallest = 0,leftBiggest = 0;
        if(!(root->left && root->right) ){
            if(!(root->left || root->right)){
                smallestOne = root->val;
                biggestOne = root->val;
                return true;
            }
            if(!root->right){
                bool leftBst =  isValidBst(root->left,leftSmallest,leftBiggest);
                biggestOne = root->val;
                smallestOne = leftSmallest;
                return leftBst && ( root->val > leftBiggest);
            }
            if(!root->left){
                bool rightBst =  isValidBst(root->right,rightSmallest,rightBiggest);
                biggestOne = rightBiggest;
                smallestOne = root->val;
                return rightBst && ( root->val < rightSmallest);
            }

        }
        bool rightBst = isValidBst(root->right,rightSmallest,rightBiggest);
        bool leftBst =  isValidBst(root->left,leftSmallest,leftBiggest);
        if(leftBst && rightBst){
            if(root->val < rightSmallest && root->val > leftBiggest){
                biggestOne = rightBiggest;
                smallestOne = leftSmallest;
                return true;
            }
        }
        return false;
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(1);
    a->right = b;
    Solution test;
    cout<<test.isValidBST(a)<<endl;
    return 0;
}
