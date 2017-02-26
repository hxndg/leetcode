#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL) return head;
        ListNode *end=head;
        while(end->next!=NULL){
            end = end->next;
        }
        return mergeSortList(head,end);
    }

    ListNode *mergeSortList(ListNode *head,ListNode *end){
        end->next = NULL;
        if(head==end) return head;
        ListNode* slow = head;
        ListNode* quick = head;
        /*   需要注意的是这里写的快慢指针的方法是错误的！对于两个节点的链表来说会出现错误,正确的写法在下面,出错的原因在于慢的指针只有当快的指针走出去两步的时候才能往前走，因此不能将慢指针往前走的写到第一步去
        while(quick!= end){     //经过运算quick变成了最后一个节点，而slow编程了中间节点
            slow = slow->next;
            quick = quick->next;
            if(quick != end){
                quick = quick->next;
            }
        }
        */
        while(quick!= end){     //经过运算quick变成了最后一个节点，而slow编程了中间节点
            quick = quick->next;
            if(quick != end){
                quick = quick->next;
                slow = slow->next;
            }
        }
        ListNode *unSortedAfter = mergeSortList(slow->next,end);   //先整理后面的数组如果先整理前面的数组，那么还需要一个变量来保存这个slow的next
        ListNode *unSortedPre = mergeSortList(head,slow);
        ListNode *sortedLast = new ListNode(0);
        ListNode *returnHead = sortedLast;
        ListNode *currentNode;
        while(unSortedPre && unSortedAfter){
            if(unSortedPre->val < unSortedAfter->val){
                currentNode = unSortedPre;
                unSortedPre = unSortedPre->next;
            }
            else{
                currentNode = unSortedAfter;
                unSortedAfter = unSortedAfter->next;
            }
            sortedLast->next = currentNode;
            sortedLast = sortedLast->next;
        }
        while( unSortedPre != NULL){
            currentNode = unSortedPre;
            unSortedPre = unSortedPre->next;
            sortedLast->next = currentNode;
            sortedLast = sortedLast->next;
        }
        while( unSortedAfter != NULL){
            currentNode = unSortedAfter;
            unSortedAfter = unSortedAfter->next;
            sortedLast->next = currentNode;
            sortedLast = sortedLast->next;
        }
        currentNode->next = NULL;
        ListNode *deleteHead = returnHead;
        delete deleteHead;
        returnHead = returnHead ->next;
        return returnHead;
    }
};

int main(){
    ListNode *a= new ListNode(1);
    ListNode *b= new ListNode(9);
    ListNode *c= new ListNode(3);
    ListNode *d= new ListNode(7);
    ListNode *e= new ListNode(12);
    ListNode *f= new ListNode(6);
    ListNode *g= new ListNode(4);
    a->next = b;b->next = c;c->next = d;
    d->next = e;e->next = f;f->next = g;

    ListNode *tmp = a;
    while(tmp != NULL){
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
    Solution test;
    ListNode *answer = test.sortList(a);

    while(answer != NULL){
        cout<<answer->val<<" ";
        answer = answer->next;
    }
    cout<<endl;
}
