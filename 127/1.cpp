#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    struct Node {
        const string* val;
        unordered_set<Node*> children;
        Node(const string& str): val(&str) {}
        Node() {} 
    };

    int calcLen1(Node* root, const string& endWord) {
        unordered_set<Node*> nodes;
        unordered_set<Node*> used;
        int len = 1;
        nodes.insert(root);
        while (nodes.size()) {
            unordered_set<Node*> next;
            for (auto node: nodes) {
                if (used.find(node) != used.end()) continue;
                if (*node->val == endWord) return len;
                used.insert(node);
                next.insert(node->children.begin(), node->children.end());
            }
            nodes.swap(next);
            ++len;
        }
        return 0;
    }

    bool check(const string& str1, const string& str2) {
        int size = str1.size();
        int ret = 0;
        for (int i = 0; i < size; ++i) if (str1[i] != str2[i]) if (++ret > 1) return false;
        return ret == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool hasEnd = false;
        wordList.push_back(beginWord);
        int len = wordList.size();
        unordered_map<string, Node> nodes;
        unordered_map<Node*, int> used;
        for (auto& word: wordList) {
            if (word == endWord) hasEnd = true;
            nodes.emplace(word, word);
        }
        if (!hasEnd) return 0;
        for (int i = 0; i < len; ++i) {
            auto& str1 = wordList[i];
            auto& node1 = nodes[str1];
            used[&node1] = INT_MAX;
            for (int j = i + 1; j < len; ++j) {
                auto& str2 = wordList[j];
                if (!check(str1, str2)) continue;
                auto& node2 = nodes[str2];
                node1.children.insert(&node2);
                node2.children.insert(&node1);
            }
        }
        return calcLen1(&nodes[beginWord], endWord);
    }
};

int main() {
    std:vector<string> words = {
        "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"
        "hot","dot","dog","lot","log","cog"
    };
    Solution solution;
    // solution.ladderLength("hit", "cog", words);
    solution.ladderLength("qa", "sq", words);
}