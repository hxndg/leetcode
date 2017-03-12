/*
    扯淡的问题

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
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        if(left != NULL){
            root->right = left;
            root->left = NULL;
            TreeNode *node = root;
            while(node->right != NULL){
                node = node->right;
            }
            node->right = right;
        }
        return;
    }


};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    TreeNode *e = new TreeNode(5);
    TreeNode *f = new TreeNode(6);
    a->left = b;
    b->left = c;
    b->right = d;
    c->left = e;
    //a->right = e;
    //e->right = f;
    Solution test;
    test.flatten(a);
    TreeNode *wtf = a;
    while(wtf != NULL){
        cout<<wtf->val<<endl;
        wtf = wtf->right;
    }
    return 0;
}
