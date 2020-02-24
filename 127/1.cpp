#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    struct Node {
        string val;
        unordered_set<Node*> children;
        Node(string str): val(str) {}
        Node() {} 
    };
    void calcLen(Node* node, unordered_map<Node*, int>& used, const string& endWord, int &ret, int len) {
        if (len >= ret || used[node] <= len) return;
        used[node] = len;
        if (node->val == endWord) {
            if (ret > len) ret = len;
            return;
        }
        for (auto child: node->children)
            used[child] = len + 2;
        for (auto child: node->children)
            calcLen(child, used, endWord, ret, len + 1);
        // used.erase(used.find(node));
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
            auto str1 = wordList[i];
            auto& node1 = nodes[str1];
            used[&node1] = INT_MAX;
            for (int j = i + 1; j < len; ++j) {
                auto str2 = wordList[j];
                if (!check(str1, str2)) continue;
                auto& node2 = nodes[str2];
                node1.children.insert(&node2);
                node2.children.insert(&node1);
            }
        }

        int ret = INT_MAX;
        calcLen(&nodes[beginWord], used, endWord, ret, 1);
        return ret == INT_MAX ? 0 : ret;
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