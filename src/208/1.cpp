#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class Trie {
    Trie* children[32];
    bool val;
public:
    /** Initialize your data structure here. */
    Trie() {
        memset(this, 0, sizeof(Trie));
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* tree = this;
        for (char ch: word) {
            char key = ch - 'a';
            if (!tree->children[key])
                tree->children[key] = new Trie();
            tree = tree->children[key];
        }
        tree->val = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* tree = this;
        for (char ch: word) {
            tree = tree->children[ch - 'a'];
            if (!tree) return false;
        }
        return tree->val;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* tree = this;
        for (char ch: prefix) {
            tree = tree->children[ch - 'a'];
            if (!tree) return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
    Trie trie;
    trie.insert("app");
}