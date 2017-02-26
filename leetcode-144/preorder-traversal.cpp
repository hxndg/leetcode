/*
  和中序遍历没有太大的区别.实现一下morris遍历方法，很不错而且非常巧妙的方法,这里有一点要很重视:
  找寻前驱节点的时候如果前驱节点没有标记，那么直接一直向右找到右孩子为空的节点即可
  如果前驱节点被标记了，那么使用找寻时候需要加上的限制条件就变成了一直向右找到右孩子不为当前节点的节点。
  这就是代码第3行两个限制条件prevNode->right != NULL和prevNode->right != root都需要的原因，只使用第一个条件会出错
  很巧妙的方法，需要知道
    TreeNode* findPrevNode(TreeNode *root){
        TreeNode * prevNode = root->left;
        while(prevNode->right != NULL && prevNode->right != root){
            prevNode = prevNode->right;
        }
        return prevNode;
    }
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        TreeNode *node = root;
        while(node){
            if(node->left == NULL){
                result.push_back(node->val);
                node = node->right;
                continue;
            }
            TreeNode *lead = findPrevNode(node);
            if(lead->right != node){
                lead->right = node;
                result.push_back(node->val);
                node = node->left;
                continue;
            }
            else{
                lead->right = NULL;
                node = node->right;
                continue;
            }
        }
        return result;
    }
    TreeNode* findPrevNode(TreeNode *root){
        TreeNode * prevNode = root->left;
        while(prevNode->right != NULL && prevNode->right != root){
            prevNode = prevNode->right;
        }
        return prevNode;
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    //TreeNode *c = new TreeNode(3);
    a->left = b;//b->left = c;
    Solution test;
    vector<int> answer = test.preorderTraversal(a);
    for(int i = 0;i < answer.size();i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
