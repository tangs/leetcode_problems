#include <stdlib.h>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        
        ListNode* ret = head;
        ListNode* l = NULL;
        ListNode* lhead = NULL;
        ListNode* r = NULL;
        ListNode* rhead = NULL;

        ListNode* p = head;
        while (p) {
            if (p->val < x) {
                if (l) l->next = p;
                else lhead = p;
                l = p;
            } else {
                if (r) r->next = p;
                else rhead = p;
                r = p;
            }
            p = p->next;            
        }
        if (l) l->next = rhead;
        if (r) r->next = NULL;

        return lhead ? lhead : rhead;
    }
};

int main() {
    ListNode node1(1), node2(4), node3(3), node4(2), node5(5), node6(2);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;

    Solution solu;
    solu.partition(&node1, 3);
}
