#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head) return NULL;
        ListNode* prev = head;
        ListNode* prevGroup = NULL;
        ListNode* p = head->next;
        ListNode* ret = NULL;
        if (!p) return head;
        int cnt = 0;
        while (p) {
            ListNode* next = p->next;
            if (!(cnt & 1)) {
                p->next = prev;
                if (prevGroup) {
                    prevGroup->next = p;
                } else {
                    ret = p;
                }
                prevGroup = prev;
            }
            ++cnt;
            prev = p;
            p = next;
        }
        if (!(cnt & 1)) prevGroup->next = prev;
        else prevGroup->next = NULL;
        return ret;
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
    // node4.next = &node5;

    Solution solution;
    solution.swapPairs(&node1);
}