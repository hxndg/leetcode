/*
    自己的想法完全跑偏了

*/


#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL) return;
        ListNode *slow = head;
        ListNode *quick =head;
        ListNode *preNode = slow;
        while(quick != NULL && quick->next != NULL){
            preNode = slow;
            slow = slow->next;
            quick = quick->next->next;
        }
        preNode->next = NULL;
        ListNode *leftHead = slow;
        leftHead = reverseList(leftHead);
        ListNode *lastNode = NULL;
        while(head != NULL && leftHead != NULL){
            ListNode *nextHead = head->next;
            ListNode *nextLeftHead = leftHead->next;
            head->next = leftHead;
            if(lastNode != NULL){
                lastNode->next = head;
            }
            lastNode = leftHead;
            head = nextHead;
            leftHead = nextLeftHead;
        }
        lastNode->next = leftHead;
      }
    ListNode *reverseList(ListNode* head){
        ListNode *currentNode = head->next;
        head->next = NULL;
        ListNode *nextNode = NULL;
        while(currentNode != NULL){
            nextNode = currentNode->next;
            currentNode->next = head;
            head = currentNode;
            currentNode = nextNode;
        }
        return head;
    }

    };

int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    a->next = b;b->next = c;c->next = d;d->next = e;
    Solution test;
    test.reorderList(a);
    ListNode *currentNode = a;
    while(currentNode != NULL){
        cout<<currentNode->val<<" ";
        currentNode = currentNode->next;
    }
    cout<<endl;
    return 0;
}
