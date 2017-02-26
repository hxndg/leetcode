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

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *preDeleteNode = head;
        ListNode *deleteNode = head;
        ListNode *endNode = deleteNode;
        while(n > 1){
            endNode = endNode ->next;
            n--;
        }
        while(endNode->next != NULL){
            preDeleteNode = deleteNode;
            endNode = endNode->next;
            deleteNode = deleteNode->next;
        }
        if(head == deleteNode) {
            head = head->next;
        }
        preDeleteNode->next = deleteNode->next;
        deleteNode->next = NULL;
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
    ListNode *head = test.removeNthFromEnd(a,5);
    while(head != NULL){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
    return 0;
}
