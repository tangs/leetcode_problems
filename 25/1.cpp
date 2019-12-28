#include <stdio.h>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1) return head;
        if (head == NULL) return NULL;
        ListNode* ret = NULL;
        int size = 0;
        ListNode* tmp = head;
        while (tmp) {
            ++size;
            tmp = tmp->next;
        }
        int len = size - (size % k);

        // ListNode* groupPrev = NULL;
        ListNode* prev = head;
        ListNode* first = head;
        ListNode* p = head->next;
        ListNode* prevFirst = NULL;
        for (int i = 1; i < len; ++i) {
            tmp = p->next;
            int idx = i % k;
            if (idx == k - 1) {
                if (!prevFirst) {
                    ret = p;
                } else {
                    prevFirst->next = p;
                }
                prevFirst = first;
                first = p->next;
            }
            if (idx != 0) {
                p->next = prev;
            }
            prev = p;
            p = tmp;
        }
        if (prevFirst) prevFirst->next = p;
        if (ret) return ret; else return head;
    }
};

int main() {
    ListNode node11(1);
    ListNode node12(2);
    ListNode node13(3);
    ListNode node14(4);
    ListNode node15(5);
    node11.next = &node12;
    node12.next = &node13;
    node13.next = &node14;
    node14.next = &node15;

    Solution solution;
    solution.reverseKGroup(&node11, 2);
}