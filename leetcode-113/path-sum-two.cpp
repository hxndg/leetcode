/*
    这道题并不难，那么问题出在哪里呢?所谓的根节点到叶子节点必须得是最终是叶子节点才可以看等不等于，不能简单的用大于或者小于来操作。
    此外必须严格遵守root->left || root->right == NULL的节点才是叶子节点，对于1,2 sum=1，这个组合，问题就出现在1的右节点会被看成是终止位置，
    而终止位置对应的节点并不一定是叶子节点，所以这道题的结束迭代条件是到没到叶子节点

    注释掉的代码就是错误的代码，错误包含在两个方面。

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> combination;
        vector<vector<int>> result;
        buildAnswer(root,sum,0,combination,result);
        return result;
    }

    void buildAnswer(TreeNode* root,int sum,int currentSum,vector<int> &combination,vector<vector<int>> &result){
        if(root == NULL) return;
        if( (root->left == NULL) && (root->right == NULL)){
            if((currentSum + root->val) == sum){
                combination.push_back(root->val);
                result.push_back(combination);
                combination.pop_back();
                return;
            }
        }
        else{
            combination.push_back(root->val);
            buildAnswer(root->left,sum,currentSum + root->val,combination,result);
            buildAnswer(root->right,sum,currentSum + root->val,combination,result);
            combination.pop_back();
            return;
        }
    }
    /*
    void buildAnswer(TreeNode* root,int sum,int currentSum,vector<int> &combination,vector<vector<int>> &result){
        if(root == NULL ) return;
        if( ((currentSum + root->val) == sum) && (root->left == NULL) && (root->right == NULL)){
            combination.push_back(root->val);
            result.push_back(combination);
            combination.pop_back();
            return;
        }
        if( (currentSum + root->val) > sum){
            return;
        }
        if( ( currentSum + root->val) < sum){
            combination.push_back(root->val);
            buildAnswer(root->left,sum,currentSum + root->val,combination,result);
            buildAnswer(root->right,sum,currentSum + root->val,combination,result);
            combination.pop_back();
            return;
        }
    }
    */
};


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(-2);
    TreeNode *c = new TreeNode(-3);
    TreeNode *d = new TreeNode(1);
    TreeNode *e = new TreeNode(3);
    TreeNode *f = new TreeNode(-2);
    TreeNode *g = new TreeNode(-1);
    //TreeNode *h = new TreeNode(2);
    //TreeNode *i = new TreeNode(5);
    //TreeNode *j = new TreeNode(1);
    a->left = b;
    a->right = c;
    b->left =d;b->right = e;
    c->left =f;//c->right = f;
    d->left =g;//d->right = h;
    //f->left =i;f->right = j;
    Solution test;
    vector<vector<int>> answer = test.pathSum(a,-1);
    for(int i = 0 ; i < answer.size() ;i ++){
        for(int j = 0; j < answer[i].size();j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
