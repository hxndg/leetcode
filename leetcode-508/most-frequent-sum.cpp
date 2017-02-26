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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> result;
        vector<int> answer;
        sumOfTree(root,result);
        sort(result.begin(),result.end());
        int maxTimes = 1,startPos = 0,endPos = 0;
        for(int i = 0 ;i<result.size();i++){
            startPos = i;
            while(i < result.size()-1 && result[i+1] == result[i]){
                i++;
            }
            endPos = i;
            int valueLength = endPos - startPos + 1;
            if(valueLength== maxTimes){
                answer.push_back(result[i]);
            }
            if(valueLength> maxTimes){
                answer.clear();
                answer.push_back(result[i]);
                maxTimes = valueLength;
            }
        }
        return answer;
    }

    int sumOfTree(TreeNode* root,vector<int> &result){
        if(root == NULL) return 0;
        int sumOfAll = 0,sumOfLeft = 0,sumOfRight = 0;
        if( root->left != NULL ) sumOfLeft = sumOfTree(root->left,result);
        if( root->right != NULL) sumOfRight = sumOfTree(root->right,result);
        sumOfAll = root->val + sumOfLeft + sumOfRight;
        result.push_back(sumOfAll);
        return sumOfAll;
    }
};



int main(){
    TreeNode *left = new TreeNode(2);
    TreeNode *right = new TreeNode(-3);
    TreeNode *root = new TreeNode(5);
    root->right = right;
    root->left = left;
    Solution test;
    vector<int> answer = test.findFrequentTreeSum(root);
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }
    return 0;
}
