#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
    Node* deepCopy(vector<Node*>& nodes, Node* node) {
        if (!node) return NULL;
        auto nodeNew = new Node(node->val);
        nodes.push_back(nodeNew);
        nodeNew->next = deepCopy(nodes, node->next);
    }
public:
    Node* copyRandomList(Node* head) {
        vector<Node*> nodes;
        auto headNew = deepCopy(nodes, head);

        auto node1 = head;
        auto node2 = headNew;
        while (node1) {
            node2->random = 
            node1 = node1->next;
            node2 = node2->next;
        }
        return headNew;
    }
};