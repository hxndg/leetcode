/*
    实际上是一个bfs问题，确实，每次我只需要找我当前层的元素即可，然后处理完了当前层我再去处理其它层的元素,
    或者说我每次处理的实际上是我下面的一层,这个题真的是非常好的一个题，就是可惜没有想出来
*/



#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        TreeLinkNode *curr = NULL;
        TreeLinkNode *head = root;
        TreeLinkNode *prev = NULL;
        while(head != NULL){
            curr = head;
            head = NULL;
            prev = NULL;
            while( curr != NULL){
                if(curr->left != NULL){
                    if(prev == NULL){
                        prev = curr->left;
                        head = curr->left;
                    }
                    else{
                        prev->next = curr->left;
                        prev = prev->next;
                    }
                }
                if(curr->right != NULL){
                    if(prev == NULL){
                        prev = curr->right;
                        head = curr->right;
                    }
                    else{
                        prev->next = curr->right;
                        prev = prev->next;
                    }
                }
                curr = curr->next;
          }
        }
    }

};
