/*
    这道题本身能够发现从相聚点到环的起点的长度和链表起点到环起点的长度相等时基本就应该做出来了，
    但是自己被具体的想求出来长度给限制住了，只想能够从数值算出来，就被卡住了，这一点很尴尬
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(true){
            if(fast == NULL) return NULL;
            if(fast->next == NULL || fast->next->next == NULL){
                return NULL;
            }
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                break;
            }
        }
        slow = head;
        while(fast != slow){
            fast = fast->next;
            slow = slow->next;
        }
        return fast;
    }
};


int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    a->next = b;
    b->next = a;
    Solution test;
    ListNode *c = test.detectCycle(a);
    cout<<c->val<<endl;
    return 0;
}
