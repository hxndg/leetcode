/*
  插入排序，非常寻常的操作。
*/




#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <limits.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode *addedHead = new ListNode(INT_MIN);
        ListNode *sortedHead = addedHead;
        ListNode *unSortedHead = head;
        while( unSortedHead != NULL){
            ListNode *unSortedNode = unSortedHead;
            unSortedHead = unSortedHead->next;
            ListNode *sortedNode = sortedHead;
            ListNode *preSortedNode = sortedHead;
            while((sortedNode !=NULL) && unSortedNode->val >= sortedNode->val){
                preSortedNode = sortedNode;
                sortedNode = sortedNode -> next;
            }
            preSortedNode->next = unSortedNode;
            unSortedNode->next = sortedNode;
        }
        return addedHead->next;
    }
};

int main(){
    ListNode *a= new ListNode(-2147483647);
    ListNode *b= new ListNode(-2147483648);
    //ListNode *c= new ListNode(3);
  //  ListNode *d= new ListNode(7);
  //  ListNode *e= new ListNode(12);
  //  ListNode *f= new ListNode(6);
  //  ListNode *g= new ListNode(4);
  //  a->next = b;b->next = c;c->next = d;
  //  d->next = e;e->next = f;f->next = g;
  a->next = b;
    ListNode *tmp = a;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    Solution test;
    ListNode *answer = test.insertionSortList(a);

    while(answer != NULL){
        cout<<answer->val<<" ";
        answer = answer->next;
    }
    cout<<endl;
}
