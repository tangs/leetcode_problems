#include <stdio.h>
#include <vector>

using namespace std;

//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTLists(ListNode* list1, ListNode* list2) {
        if (!list1 || !list2) return NULL;
        ListNode *cur, *other;
        if (list1->val > list2->val) {
            cur = list2;
            other = list1;
        } else {
            cur = list1;
            other = list2;
        }
        ListNode* prev = cur;
        ListNode* head = cur;
        cur = cur->next;
        while (cur) {
            if (cur->val <= other->val) {
                prev = cur;
                cur = cur->next;
            } else {
                prev->next = other;
                ListNode* tmp = cur;
                cur = other;
                other = tmp;
            }
        }
        prev->next = other;
        return head;
    }

    inline int getMinIdx(vector<ListNode*>& curPos, int& size) {
        size = 0;
        int ret = -1;
        int len = curPos.size();
        for (int i = 0; i < len; ++i) {
            auto node = curPos[i];
            if (node) {
                ++size;
                if (ret == -1) ret = i;
                else if (curPos[ret]->val > node->val) ret = i;
            }
        }
        return ret;
    }

    inline void next(vector<ListNode*>& curPos, int idx) {
        curPos[idx] = curPos[idx]->next;
    }

    inline bool hasValue(vector<ListNode*>& curPos, int idx) {
        return curPos[idx] != NULL;
    }

    inline int value(vector<ListNode*>& curPos, int idx) {
        return curPos[idx]->val;
    }

    inline bool equals(vector<ListNode*>& curPos, int idx1, int idx2) {
        return hasValue(curPos, idx1) && hasValue(curPos, idx2) &&
            value(curPos, idx1) == value(curPos, idx2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // int len = lists.size();
        // if (len == 0) return NULL;
        // vector<ListNode*> curPos(lists);
        // int size;
        // int headPos = getMinIdx(curPos, size);
        // if (headPos == -1) return NULL;
        // ListNode* head = curPos[headPos];
        // ListNode* prev = head;
        // int prevPos = headPos;
        // next(curPos, headPos);
        // for (;;) {
        //     int size;
        //     int pos = getMinIdx(curPos, size);
        //     if (size == 1) {
        //         prev->next = curPos[pos];
        //         break;
        //     }
        //     if (pos == -1) break;
        //     ListNode* cur = curPos[pos];
        //     if (pos != prevPos) {
        //         prev->next = cur;
        //         prevPos = pos;
        //     }
        //     prev = cur;
        //     next(curPos, prevPos);
        // }
        // return head;
        int len = lists.size();
        if (len == 0) return NULL;
        ListNode* ret = lists[0];
        for (int i = 1; i < len; ++i) {
            ret = mergeTLists(ret, lists[i]);
        }
        return ret;
    }
};

int main() {
    vector<ListNode*> lists;

    ListNode node11(1);
    ListNode node12(4);
    ListNode node13(5);
    node11.next = &node12;
    node12.next = &node13;

    ListNode node21(1);
    ListNode node22(3);
    ListNode node23(4);
    node21.next = &node22;
    node22.next = &node23;

    ListNode node31(2);
    ListNode node32(6);
    node31.next = &node32;

    lists.push_back(&node11);
    lists.push_back(&node21);
    lists.push_back(&node31);

    Solution solution;
    solution.mergeKLists(lists);
}
