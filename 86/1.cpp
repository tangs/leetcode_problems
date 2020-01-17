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
        ListNode* p = head;
        vector<ListNode*> vec1;
        vector<ListNode*> vec2;
        // vector<ListNode*> vec3;
        int l = 0;
        while (p) {
            if (p->val < x) {
                vec1.push_back(p);
            } else {
                vec2.push_back(p);
            }
            p = p->next;
        }
        
        p = NULL;
        // ListNode* prev = NULL;

        for (auto cur: vec1) {
            if (!p) head = cur;
            if (p) p->next = cur;
            p = cur;
            p->next = NULL;
        }
        for (auto cur: vec2) {
            if (!p) head = cur;
            if (p) p->next = cur;
            p = cur;
            p->next = NULL;
        }

        return head;
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
