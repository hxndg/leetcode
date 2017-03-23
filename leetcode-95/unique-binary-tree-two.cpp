#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        map<int,vector<TreeNode*>> hashMap;
        if(n == 0){
            vector<TreeNode*> empty;
            return empty;
        }
        return generateTrees(n,hashMap);
    }
    vector<TreeNode*> generateTrees(int n,map<int,vector<TreeNode*>> &hashMap) {
        map<int,vector<TreeNode*>>::iterator iter = hashMap.find(n);
        if(iter != hashMap.end()){
            return iter->second;
        }
        vector<TreeNode*> result;
        if(n == 0){
            result.push_back(NULL);
            return result;
        }
        for(int i = 1 ; i <= n ; i ++){
            vector<TreeNode*> leftTree = generateTrees(i-1,hashMap);
            vector<TreeNode*> rightTree = generateTrees(n-i,hashMap);
            for(int j = 0 ; j < leftTree.size(); j++){
                for(int k = 0 ; k < rightTree.size(); k++){
                    TreeNode *root = new TreeNode(i);
                    root->left = copyTree(leftTree[j],0);
                    root->right = copyTree(rightTree[k],i);
                    result.push_back(root);
                }
            }
        }
        hashMap.insert(make_pair<int,vector<TreeNode*>>(int(n),vector<TreeNode*>(result)));
        return result;
    }

    TreeNode* copyTree(TreeNode *node,int addValue){
        if(node == NULL){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(node->val+addValue);
        newNode->left = copyTree(node->left,addValue);
        newNode->right = copyTree(node->right,addValue);
        return newNode;
    }
};

void preorder(TreeNode* root){
    TreeNode* node = root;
    if(node == NULL){
        return;
    }
    cout<<node->val<<" ";
    preorder(node->left);
    preorder(node->right);
}


int main(){
    int n = 3;
    Solution test;
    vector<TreeNode*> answer = test.generateTrees(n);
    for(int i = 0 ; i < answer.size(); i++){
        preorder(answer[i]);
        cout<<endl;
    }
    return 0;
}
