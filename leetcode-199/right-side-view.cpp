/*
   这个题解法众多，不需要多说什么

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL){
            return result;
        }
        result.push_back(root->val);
        vector<int> rightAnswer = rightSideView(root->right);
        vector<int> leftAnswer = rightSideView(root->left);
        int i = 0;
        for(i = 0; i < rightAnswer.size();i++){
            result.push_back(rightAnswer[i]);
        }
        while(i < leftAnswer.size()){
            result.push_back(leftAnswer[i]);
            i++;
        }
        return result;
    }
};


int main(){
    TreeNode *a = new TreeNode(1);
    TreeNode *b = new TreeNode(2);
    TreeNode *c = new TreeNode(3);
    TreeNode *d = new TreeNode(4);
    a->left = b; a->right = c;
    b->left = d;
    Solution test;
    vector<int> answer = test.rightSideView(a);
    for(int i = 0 ;i < answer.size(); i++){
        cout<<answer[i]<<" ";
    }
    cout<<endl;
    return 0;
}
