#include <stdio.h>
#include <bitset>
#include <string.h>
#include <ctime>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return NULL;

        ListNode* ret = head;
        ListNode* prev = ret;
        ListNode* p = head;

        while (p) {
            ListNode* next = p->next;
            int val = p->val;
            while (next && next->val == val) next = next->next;
            if (p->next != next) {
                if (ret->val == val) {
                    ret = next;
                } else {
                    prev->next = next;
                }
                // prev = next;
            } else {
                prev = p;
            }
            p = next;
        }
        return ret;
    }
};

int main() {
    ListNode node1(1), node2(2), node3(3), node4(3), node5(4), node6(4), node7(5);
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = &node6;
    node6.next = &node7;

    Solution solu;
    solu.deleteDuplicates(&node1);
}