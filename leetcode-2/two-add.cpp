#include <vector>
#include <map>
#include <iostream>
#include <string>

using namespace std;

 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode * head = new ListNode(0);
        ListNode * old_head = head;
        int carry = 0;
        /*
        while(p1 != NULL && p2 != NULL){
           int num = p1->val + p2->val+carry;
           carry = num / 10;
           num = num %10;
           ListNode* answer = new ListNode(num);
           head->next = answer;
           head = head->next;
           p1 = p1->next;
           p2 = p2->next;
        }

        while(p1 != NULL){
            int num = p1->val+carry;
            carry = num / 10;
            num = num %10;
            ListNode* answer = new ListNode(num);
            head->next = answer;
            head = head->next;
            p1 = p1->next;
        }
        while(p2 != NULL){
            int num = p2->val+carry;
            carry = num / 10;
            num = num %10;
            ListNode* answer = new ListNode(num);
            head->next = answer;
            head = head->next;
            p2 = p2->next;
        }
        if(carry == 1 && p1==NULL && p2==NULL){
            ListNode* answer = new ListNode(carry);
            head->next = answer;
            head = head->next;
        }
        */
        while(p1 != NULL || p2 != NULL || carry != 0){
            int p1Val = ( p1 != NULL? p1->val:0 );
            int p2Val = ( p2 != NULL? p2->val:0 );
            int num = p1Val + p2Val + carry;
            carry = num / 10;
            num = num % 10;
            if(p1 != NULL){
                p1 = p1->next;
            }
            if(p2 != NULL){
                p2 = p2->next;
            }
            ListNode* answer = new ListNode(num);
            head->next = answer;
            head = head->next;
      }

    head = old_head->next;
    delete old_head;
    return head;
    }
};




int main(){
  ListNode *node1 = new ListNode(2);
  ListNode *node2 = new ListNode(4);
  ListNode *node3 = new ListNode(3);
  node1->next = node2;
  node2->next = node3;
  ListNode *node4 = new ListNode(5);
  ListNode *node5 = new ListNode(6);
  ListNode *node6 = new ListNode(4);
  node4->next = node5;
  node5->next = node6;
  Solution test;
  ListNode * result = test.addTwoNumbers(node1,node4);
  for(;result != NULL;result = result->next){
      cout<<result->val<<endl;
  }
  return 0;

}
