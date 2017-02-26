/*
    水塘抽样伪代码：
    ReservoirSample(S[1,n],R[1,k])

    for i = 1 to k;
        R[i] := S[i]
    endfor
    for i = k+1 to n:
        j: = random(1,i)
        if j<= k:
            R[j] := S[i]
    这个题除了有一个水桶抽样需要理解之外，还有一点就是这段代码里有一个
            int j = rand()%i;
    需要理解，当j == 0时，这段代码就碰上了1/i的概率，这一点需要注意。

*/

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
    ListNode * head;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this.head = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
        int res = head->val;
        ListNode *node = head->next;
        int i = 2;
        while(node){
            int j = rand()%i;
            if(j == 0)
              res = node->val;
            i++;
            node = node->next;
        }
        return res;
    }
};


int main(){
    ListNode *a = new ListNode(1);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(3);
    a->next = b;b->next = c;
    Solution *test = new Solution(a);
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    cout<< test->getRandom()<<endl;
    return 0;
}
