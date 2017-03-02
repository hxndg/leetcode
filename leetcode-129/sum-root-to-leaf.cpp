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
    int sumNumbers(TreeNode* root) {
        vector<int> nums;
        buildAnswer(root,nums,0);
        int sum = 0;
        for(int i = 0 ; i < nums.size() ;i ++){
            sum += nums[i];
        }
        return sum;
    }

    void buildAnswer(TreeNode* root,vector<int>&nums,int num){
        if( root == NULL ) return;
        if( (root->left==NULL) && (root->right==NULL) ){
            nums.push_back(num*10 + root->val);
        }
        else{
            buildAnswer(root->left,nums,num*10+root->val);
            buildAnswer(root->right,nums,num*10+root->val);
        }
    }
};

int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(3);
    a->left = b;a->right = c;
    b->left = d;
    Solution test;
    cout<<"answer is "<<test.sumNumbers(a)<<endl;
    return 0;
}
