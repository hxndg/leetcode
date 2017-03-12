/*
    基本想法比较简单，就是找到中间节点，然后进行将链表截成两端，然后开始创建树即可
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode *node = head,*preNode = NULL;
        if(head == NULL) return NULL;
        int nodeNum = 0,rootVal = 0;
        while(node != NULL){
            node = node->next;
            nodeNum++;
        }
        node = head;
        int rootSeq = nodeNum/2;
        while(rootSeq > 0){
            preNode = node;
            node = node->next;
            rootSeq --;
        }
        ListNode *afterNode = node->next;
        node->next = NULL;
        TreeNode *root = new TreeNode(node->val);
        if(preNode != NULL){
            preNode->next = NULL;
        }
        root->right = sortedListToBST(afterNode);
        if(preNode != NULL){
            root->left = sortedListToBST(head);
        }
        return root;
    }

    void preOrder(TreeNode *root){
        if(root == NULL) return ;
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
        return ;
    }
};


int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(6);
    ListNode *g = new ListNode(7);
    ListNode *h = new ListNode(8);
    a->next = b; b->next = c;c->next = e;
    e->next = f;f->next = g;g->next = h;
    Solution test;
    TreeNode *tmp = test.sortedListToBST(a);
    test.preOrder(tmp);
    return 0;
}
