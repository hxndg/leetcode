/*

   总算明白了为什么你的代码有问题了，使用morris代码本身是没有错的，
   你的问题在于过早的跳回，当你跳回的时候应当首先回复原本树的结构，也就是删除掉你原本添加的线索，否则多次调用的情况下就会出错
   太难想到了......操作不是可恢复型的。。。太伤了，需要记住。。。
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
    int kthSmallest(TreeNode* root, int k) {
        int index = k,target = 0;
        TreeNode* node = root;
        while(node){
            if(node->left == NULL) {
                if(index == 1) target = node->val;
                node = node->right;
                index--;
                continue;
            }
            TreeNode *prevNode = findPrevNode(node);
            if(prevNode->right != node){
                prevNode->right = node;
                node = node->left;
                continue;
            }
            else{
                prevNode->right = NULL;
                if(index == 1) target = node->val;
                node = node->right;
                index--;
                continue;
            }
        }
        return target;
    }

    TreeNode *findPrevNode(TreeNode* root){
        TreeNode* node = root->left;
        while(node->right != NULL && node->right != root){
            node= node->right;
        }
        return node;
    }
};


int main(){
    TreeNode *a = new TreeNode(0);
    TreeNode *b= new TreeNode(1);
    TreeNode *c= new TreeNode(2);
    TreeNode *e= new TreeNode(3);
    TreeNode *f= new TreeNode(4);
    TreeNode *g = new TreeNode(5);
    a->right = b;
    c->left = a;
    c->right = f;
    f->right = g;
    f->left = e;
    Solution test;
    int n =1;
    while(n < 6){
        cout<< test.kthSmallest(c,n)<<"    "<<endl;

        n++;
    }
    return 0;
}
