#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
    struct Node {
        const string* val;
        Node* parent;
        Node(const string* str, Node* p): val(str), parent(p) {}
    };
    bool check(const string& str1, const string& str2) {
        int len = str1.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i) if (str1[i] != str2[i]) if (++cnt > 1) return false;
        return cnt;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // wordList.push_back(move(beginWord));
        
        vector<vector<string>> ret;
        // unordered_set<string*> searchedWords;

        unordered_map<string*, Node*> words;
        auto head = new Node(&beginWord, NULL);
        words.emplace(&beginWord, head);
        
        while (words.size() && !ret.size()) {
            unordered_map<string*, Node*> next;
            for (auto it: words) {
                auto node = it.second;
                auto str = it.first;
                // if (searchedWords.find(str) != searchedWords.end()) continue;
                // searchedWords.insert(str);
                if (*str == endWord) {
                    vector<string> strs;
                    auto parent = node;
                    while (parent) {
                        strs.push_back(*(parent->val));
                        parent = parent->parent;
                    }
                    int p = 0, q = strs.size() - 1;
                    while (p < q) std::swap(strs[p++], strs[q--]);
                    ret.push_back(move(strs));
                } else if (!ret.size()) {
                    for (auto& word: wordList) {
                        if (!check(word, *str)) continue;

                        bool has = false;
                        auto parent = node;
                        while (parent) {
                            if (parent->val == &word) {
                                has = true;
                                break;
                            }
                            parent = parent->parent;
                        }
                        if (has) continue;
                        auto node1 = new Node(&word, node);
                        next.emplace(&word, node1);
                    }
                }
            }
            words.swap(next);
        }
        return ret;
    }
};

int main() {
    std:vector<string> words = {
        // "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"
        // "hot","dot","dog","lot","log","cog"
        "hot","dot","dog","lot","log","cog"
    };
    Solution solution;
    // solution.ladderLength("hit", "cog", words);
    // solution.findLadders("qa", "sq", words);
    solution.findLadders("hit", "cog", words);
}