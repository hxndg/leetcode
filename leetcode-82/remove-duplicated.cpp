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
    ListNode* deleteDuplicates(ListNode* head) {
        vector<int> result;
        if(head == NULL) return NULL;
        ListNode *node = head->next,currentValue = head->val;
        result.push_back(head->val);
        while(node != NULL){
            if(result.size() != 0 && node->val == result.back()){
                while(node!= NULL && node->val == result.back()){
                    node = node->next;
                }
                result.pop_back();
            }
            if(node != NULL){
                if(result.size() == 0 || node->val != result.back()){
                    result.push_back(node->val);
                    node = node->next;
                }  
            }

        }
        ListNode *newHead = NULL, *preNode= NULL;
        for(int i = 0 ; i < result.size();i++){
            ListNode *tmp = new ListNode(result[i]);
            if(i == 0) {
                newHead = tmp;
                preNode = tmp;
                continue;
            }
            preNode->next = tmp;
            preNode = preNode->next;
        }
        return newHead;
    }
};
int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(1);
    ListNode *c = new ListNode(3);
    ListNode *d = new ListNode(3);
    ListNode *e = new ListNode(4);
    ListNode *f = new ListNode(4);
    ListNode *g = new ListNode(5);
    a->next = b;//b->next = c;c->next = d;d->next = e;e->next = f;f->next = g;
    Solution test;
    ListNode *answer = test.deleteDuplicates(a);
    while(answer != NULL){
        cout<<answer->val<<" ";
        answer = answer->next;
    }
    cout<<endl;
    return 0;
}
