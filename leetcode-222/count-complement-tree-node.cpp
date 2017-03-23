/*
    说白了，这个东西就是看究竟左子树是满二叉树，还是右子树是满二叉树，
    然后将问题缩小一半，想法金丹，不过我还是想到最麻烦或者说最直接的想法去了
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if(h == 0){
            return 1;
        }
        if(h == -1){
            return 0;
        }
        if(height(root->right) == h-1){
            return  (1 << h) + countNodes(root->right);
        }
        else{
            return (1 << h-1) + countNodes(root->left);
        }
    }
    int height(TreeNode * root){
        return root == NULL ? -1 : 1 + height(root->left);
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    a->left = b ; a->right = c;
    Solution test;
    cout<<" answer is "<<test.countNodes(a)<<endl;
    return 0;
}
