/*  使用栈来做这道题就是相当于作弊，这道题的答案提出了一种非常巧妙的方法，首先需要将两个链表的长度都计算出来，
    计算完毕，将两个数组低位优先的合并到一起，以测试样例[7,2,4,3]和[5,6,4]为例，经过上述操作之后整个链表变成[4,3,6,4,5,2,7]
    因为保存着短的数组的长度，因此只需要将相邻的短的两个数字加起来就可以知道低位的长度，之后就可以逆序合并两个数组并进行输出了
    最先使用的方式是使用栈，下面的代码是用这种巧妙的做法，但是这种方法必须要知道两个链表的长度。而且时间复杂度貌似比栈要高。
*/





#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int l1Length = 0,l2Length = 0,minLength = 0;
        ListNode *head1 = l1,*head2 = l2;
        while(head1){
            head1 = head1->next;
            l1Length++;
        }
        while(head2){
            head2 = head2->next;
            l2Length++;
        }
        head1 = l1,head2 = l2;
        minLength = min(l1Length,l2Length);
        ListNode *head = NULL;
        while(l1Length > 0 || l2Length >0){
            int val = 0;
            if(l1Length >= l2Length){
                val = head1->val;
                head1 = head1->next;
                l1Length--;
            }else{
                val = head2->val;
                head2 = head2->next;
                l2Length--;
            }
            head = reverse(val,head);
        }
        int carry = 0;
        ListNode *res = NULL;
        while(head != NULL){
            int sum = 0;
            if(minLength >0){
                sum = head->val + head->next->val+carry;
                head = head->next->next;
                minLength --;
            }
            else{
                sum = head->val +carry;
                carry = 0;
                head = head->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            res = reverse(sum,res);
        }
        if(carry == 1) res= reverse(carry,res);
        return res;
    }

    ListNode *reverse(int val,ListNode *head){
        ListNode *node = new ListNode(val);
        node->next = head;
        return node;
    }
};


int main(){
    ListNode *a = new ListNode(5);
    //ListNode *b = new ListNode(2);
    //ListNode *c = new ListNode(4);
    //ListNode *d = new ListNode(3);
    //a->next=b;b->next = c;c->next = d;

    ListNode *e = new ListNode(5);
    //ListNode *f = new ListNode(6);
    //ListNode *g = new ListNode(4);
    //e->next = f;f->next=g;
    Solution test;
    ListNode *head = test.addTwoNumbers(a,e);
    while(head != NULL){
       cout<<head->val<<"->";
       head = head->next;
    }
    return 0;
}
