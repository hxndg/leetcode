/*
  这个题做法可以使用递归来做。
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
    ListNode* swapPairs(ListNode* head) {
        ListNode *curr = head;
        int length = 0;
        while(curr){
            curr = curr->next;
            length++;
        }
        if(length <=1 ) return head;
        ListNode *pre = NULL,*leftHead = NULL,*result = head->next;
        curr = head;
        int totalLength = length;
        while(length > 1 ){
            if(totalLength > length){
                pre->next = curr->next;
            }
            pre = curr;
            leftHead = curr->next->next;
            curr->next->next = curr;
            curr->next = leftHead;
            curr = curr->next;
            length = length - 2;
        }
       return result;
    }
};

int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    //ListNode *d = new ListNode(4);
    a->next = b;b->next= c;//c->next = d;
    Solution test;
    ListNode *result = test.swapPairs(a);
    while(result){
        cout<<result->val<<"->";
        result = result->next;
    }
    return 0;
}
