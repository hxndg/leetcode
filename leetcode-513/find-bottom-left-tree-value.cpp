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
    int findBottomLeftValue(TreeNode* root) {
        int value = 0;
        int row = getRowAndValue(value,root);
        return value;
    }

    int getRowAndValue(int &i,TreeNode *head){  //函数的返回值是最深的层，对i操作使得i经过操作之后对应于最深层的左边的元素
        if(head == NULL){
            return 0;
        }
        i = head->val;
        int rowLeft = 0,rowRight = 0,valueLeft = 0,valueRight = 0;
        rowLeft = getRowAndValue(valueLeft,head->left);
        rowRight = getRowAndValue(valueRight,head->right);
        if(rowLeft > rowRight){
            i = valueLeft;
            return rowLeft+1;
        }
        if(rowRight > rowLeft){
            i = valueRight;
            return rowRight+1;
        }
        if(rowLeft == rowRight && rowLeft==0){
            return 1;
        }
        if(rowLeft == rowRight && rowLeft != 0){
            i = valueLeft;
            return rowLeft + 1;
        }
    }
};


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(7);
    TreeNode *d = new TreeNode(3);
    a->left = c;a->right = b;b->right = d;
    Solution test;
    cout<<test.findBottomLeftValue(a)<<endl;
    return 0;
}
