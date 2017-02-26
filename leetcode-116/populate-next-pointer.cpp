/*
    基本的操作，因为要求常量空间，而对子树的操作并不能知道对相邻元素怎么做，所以只能这样子干
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        connect(root->left);
        connect(root->right);
        TreeLinkNode *leftNode = root->left;
        TreeLinkNode *rightNode = root->right;
        root->next = NULL;
        while(leftNode != NULL){
            leftNode->next = rightNode;
            leftNode = leftNode->right;
            rightNode = rightNode->left;
        }
    }
};
