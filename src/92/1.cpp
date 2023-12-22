#include <stdlib.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* first = head;
        for (int i = 2; i < m; ++i) first = first->next;
        ListNode*p = first->next;
        ListNode*prev = first;
        // ListNode* tmp = NULL;
        if (m == 1) --n;
        for (int i = m; i <= n; ++i) {
            ListNode* tmp = p->next;
            p->next = prev;
            prev = p;
            p = tmp;
        }
        if (m == 1) {
            first->next = p;
            head = prev;
        } else {
            if (first->next) {
                first->next->next = p;
                first->next = prev;
            }
        }

        return head;
    }
};

int main() {
    ListNode node1(1);
    ListNode node2(2);
    ListNode node3(3);
    ListNode node4(4);
    ListNode node5(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    Solution solu;
    solu.reverseBetween(&node1, 2, 5);
}
