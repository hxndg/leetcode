#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
         ListNode *preNode = NULL,*node = head,*afterNode = NULL;
         for(int  i = 1 ; i < m; i ++){
            preNode = node;
            node = node->next;
         }
         for(int i = m ; i < n; i++){
            node = node->next;
         }
         afterNode = node->next;
         node->next = NULL;
         if(preNode != NULL){
             preNode->next = reverseList(preNode->next,afterNode);
         }
         else{
             head = reverseList(head,afterNode);
         }
         return head;
    }

    ListNode* reverseList(ListNode *head, ListNode *afterNode){
        ListNode *currentNode = head,*preNode = NULL,*lastNode = head;
        while(currentNode != NULL){
            preNode = currentNode;
            currentNode = currentNode->next;
            preNode->next = head;
            head = preNode;
        }
        lastNode->next = afterNode;
        return head;
    }
};


int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(6);
    a->next = b;b->next = c;//c->next =d;d->next = e;e->next=f;
    Solution test;
    int m = 3,n = 3;
    ListNode *answer = test.reverseBetween(a,m,n);
    while(answer != NULL){
        cout<<answer->val<<" ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}
