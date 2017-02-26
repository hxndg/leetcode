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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL ) return head;
        ListNode * currentNode = head;int currentNum = 1;
        ListNode * lastOdd = head;
        ListNode * lastEven = head->next;
        while( currentNode != NULL){
            ListNode* nextToDeal = currentNode->next;
            if(((currentNum & 1 )!= 0) && (currentNum != 1) ){     //这一步说明是个奇数
                lastEven ->next = currentNode->next;
                currentNode->next = lastOdd->next;
                lastOdd->next = currentNode;
                lastOdd = currentNode;
                lastEven = lastEven->next;
            }
            currentNode = nextToDeal;
            currentNum ++;
        }
        return head;
    }
};


int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(4);
    //ListNode *e = new ListNode(5);
    a->next = b;b->next = c;c->next = d;//d->next = e;
    Solution test;
    ListNode * answer = test.oddEvenList(a);
    while(answer != NULL){
        cout<<answer->val<<" ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}
