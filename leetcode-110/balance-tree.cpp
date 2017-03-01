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
    bool isBalanced(TreeNode* root) {
        int hight = 0;
        return isBalanced(root,hight);
    }

    bool isBalanced(TreeNode* root,int &hight){
        if(root == NULL){
            return true;
            hight = 0;
        }
        int rightHight = 0,leftHight = 0;
        bool leftBalanced = isBalanced(root->left,leftHight);
        bool rightBalanced = isBalanced(root->right,rightHight);
        if((leftBalanced && rightBalanced) == false){
            return false;
        }
        if(abs(leftHight - rightHight) > 1){
            return false;
        }
        hight = max(leftHight,rightHight) + 1;
        return true;
    }
};


int main()
