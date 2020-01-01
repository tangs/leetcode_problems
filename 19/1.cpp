#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* dest = p;
        int cnt = 0;
        while (p) {
            if(++cnt > n + 1) dest = dest->next;
            p = p->next;
        }
        if (cnt == n) return head->next;
        ListNode* next = dest->next;
        if (next) dest->next = next->next;
        return head;
    }
};
