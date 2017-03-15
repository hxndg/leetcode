#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *prePart = new ListNode(0),*preHead = prePart;
        ListNode *afterPart = new ListNode(0),*afterHead = afterPart;
        while(head != NULL){
            if(head->val < x){
                ListNode *tmp = new ListNode(head->val);
                prePart->next = tmp;
                prePart = prePart->next;
            }
            else{
                ListNode *tmp = new ListNode(head->val);
                afterPart->next = tmp;
                afterPart = afterPart->next;
            }
            head = head->next;
        }
        prePart->next = afterHead->next;
        head = preHead->next;
        delete afterHead;
        delete preHead;
        return head;
    }
};

int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(4);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(2);
    ListNode *e = new ListNode(5);
    ListNode *f = new ListNode(2);
    a->next = b ; b->next = c; c->next = d;
    d->next = e ; e->next = f;
    Solution test;
    int x = 3;
    ListNode *answer = test.partition(a,x);
    while(answer != NULL){
        cout<<answer->val<<"->";
        answer = answer ->next;
    }
    cout<<"NULL"<<endl;
    return 0;
}
