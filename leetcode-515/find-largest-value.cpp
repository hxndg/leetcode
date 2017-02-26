#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};





class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        vector<int> leftSubTree = largestValues(root->left);
        vector<int> rightSubTree = largestValues(root->right);
        int minLength = min(leftSubTree.size(),rightSubTree.size());
        result.push_back(root->val);
        int i = 0;
        for(i = 0;i< minLength;i++){
            result.push_back( max( leftSubTree[i],rightSubTree[i] ) );
        }
        while(i < leftSubTree.size()){
            result.push_back(leftSubTree[i++]);
        }
        while(i < rightSubTree.size()){
            result.push_back(rightSubTree[i++]);
        }
        return result;
    }
};


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(3);
    TreeNode *c = new TreeNode(2);
    TreeNode *d = new TreeNode(5);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(9);
    a->left = b;a->right = c;
    b->left = d;b->right = e;
    c->right = f;
    Solution test;
    vector<int> result = test.largestValues(a);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
    return 0;
}
