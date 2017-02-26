#include <iostream>
#include <stdio.h>
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || head == NULL) return head;
        ListNode * oldHead = head;
        ListNode * end = NULL;
        ListNode * preEnd = NULL;
        int length = 0 ;
        while( head!= NULL  ){
            end = head;
            head = head->next;
            length ++;
        }
        int kByLeft ;
        k = k % length;
        if(length < k) kByLeft =2;
        else kByLeft = length - k + 1;
        if(k == 0 || length == 1) return oldHead;

        head = oldHead;
        while(head != NULL && kByLeft > 1){
            if(kByLeft == 2) preEnd = head;
            head = head->next;
            kByLeft--;
        }
        end->next = oldHead;
        preEnd->next = NULL;
        return head;

    }
};


int main(){
    ListNode * a = new ListNode(1);
    ListNode * b = new ListNode(2);
    a->next = b;

    Solution test;
    ListNode * tmp =test.rotateRight(a,3);
    cout<<tmp->val<<tmp->next->val<<endl;
    return 0;
}
