/*
  深度有限遍历的一个简单应用，不过当时怎么没想出来呢？
  不过标准答案的解法比你的解法简单多了，而且也方便快捷，哈哈
*/



#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        if(root == NULl || root == p ||root == q) return root;
        TreeNode *leftNode = lowestCommonAncestor(root->left,p,q);
        TreeNode *rightNode = lowestCommonAncestor(root->right,p,q);
        return !leftNode? :!rightNode?left:root;
        */
        stack<TreeNode*> storeWayOfP;
        stack<TreeNode*> storeWayOfQ;
        dfs(root,p,storeWayOfP);
        dfs(root,q,storeWayOfQ);
        int depthOfP = storeWayOfP.size();
        int depthOfQ = storeWayOfQ.size();
        if(depthOfP > depthOfQ){
            while(depthOfP > depthOfQ){
                storeWayOfP.pop();
                depthOfP--;
            }
        }
        if(depthOfP < depthOfQ){
            while(depthOfQ > depthOfP){
                storeWayOfQ.pop();
                depthOfQ--;
            }
        }
        while(true){
            TreeNode *nodeInPWay = storeWayOfP.top();
            TreeNode *nodeInQWay = storeWayOfQ.top();
            if(nodeInQWay == nodeInPWay){
                return nodeInPWay;
            }
            else{
                storeWayOfP.pop();
                storeWayOfQ.pop();
            }
        }

    }

    bool dfs(TreeNode *root,TreeNode* p,stack<TreeNode*> &storeWay){
        if(root == NULL) return false;
        storeWay.push(root);
        if(root == p){
            return true;
        }
        bool leftFind = dfs(root->left,p,storeWay);
        bool rightFind = dfs(root->right,p,storeWay);
        if(leftFind || rightFind){
            return true;
        }
        else{
            storeWay.pop();
            return false;
        }
    }
};



int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(4);
    TreeNode *g = new TreeNode(5);
    TreeNode *h = new TreeNode(6);
    TreeNode *i = new TreeNode(7);
    TreeNode *j = new TreeNode(9);
    TreeNode *c = new TreeNode(10);
    TreeNode *c = new TreeNode(11);

    a->right = c;a->left = b;
    Solution test;
    TreeNode *result = test.lowestCommonAncestor(a,b,c);
    cout<<"a's value is "<<result->val<<endl;
    return 0;
}
