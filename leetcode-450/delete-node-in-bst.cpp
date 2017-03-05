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
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root == NULL) return root;
        if(root->val == key){
          if(root->right == NULL){
              TreeNode *left = root->left;
              delete root;
              return left;
          }
          else{
              TreeNode *right = root->right;
              while(right->left != NULL){
                  right = right->left;
              }
              int tmp = root->val;
              root->val = right->val;
              right->val = tmp;
          }
        }
        root->left = deleteNode(root->left,key);
        root->right = deleteNode(root->right,key);
        return root;
    }
};


int main(){
    TreeNode *a = new TreeNode(5);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(6);
    TreeNode *d = new TreeNode(2);
    TreeNode *e = new TreeNode(4);
    TreeNode *f = new TreeNode(7);
    a->left = b;a->right = c;
    b->left = d;b->right = e;
    c->right = f;
    Solution test;
    test.deleteNode(a,3);
    return 0;
}
