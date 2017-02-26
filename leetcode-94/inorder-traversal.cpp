/*
   这道题并不难，但是你的方法对空间的复杂度要求同样为O(n)，使用morris算法能够使用的空间复杂度为1，链接见下方：
   http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
*/




#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        set<TreeNode*> hashSet;
        stack<TreeNode*> treeStack;
        treeStack.push(root);
        while(!treeStack.empty()){
            TreeNode *node = treeStack.top();
            if(hashSet.find(node) != hashSet.end()){
                result.push_back(node->val);
                treeStack.pop();
            }
            else{
                treeStack.pop();
                if(node->right != NULL) treeStack.push(node->right);
                treeStack.push(node);
                if(node->left != NULL) treeStack.push(node->left);
                hashSet.insert(node);
            }
        }
        return result;
    }
};


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    a->right = b;b->left = c;
    Solution test;
    vector<int> answer = test.inorderTraversal(a);
    for(int i = 0;i < answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
