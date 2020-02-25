#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;
        for (auto& word: wordList) wordSet.insert(move(word));

        if (wordSet.find(endWord) == wordSet.end()) return 0;

        unordered_set<string> wordsFront;
        unordered_set<string> nextWordsFront;
        unordered_set<string> reachedWordsFront;

        unordered_set<string> wordsBack;
        unordered_set<string> reachedWordsBack;

        unordered_set<string>* words = &wordsFront;
        unordered_set<string>* reachedWords = &reachedWordsFront;

        wordsFront.insert(beginWord);
        wordsBack.insert(endWord);

        int depth = 1;
        bool isFront = true;
        while (words->size()) {
            
            unordered_set<string> nextWords;
            auto& reachedWordsOpposite = isFront 
            ? reachedWordsBack : reachedWordsFront;
            for (auto word: *words) {
                if (reachedWords->find(word) != reachedWords->end()) continue;
                int len = word.size();
                for (int i = 0; i < len; ++i) {
                    char ch = word[i];
                    for (char ch1 = 'a'; ch1 <= 'z'; ++ch1) {
                        if (ch == ch1) continue;
                        word[i] = ch1;
                        if (reachedWordsOpposite.find(word) != reachedWordsOpposite.end()) 
                            return depth;
                        if (wordSet.find(word) != wordSet.end() && 
                        reachedWords->find(word) == reachedWords->end())
                            nextWords.insert(word);
                        word[i] = ch;
                    }
                }
                reachedWords->insert(move(word));
            }
            words->swap(nextWords);
            if (isFront) {
                words = &wordsBack;
                reachedWords = &reachedWordsBack;
            } else {
                words = &wordsFront;
                reachedWords = &reachedWordsFront;
            }
            ++depth;
            isFront = !isFront;
        }
        return 0;
    }
};

int main() {
    std:vector<string> words = {
        // "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"
        // "hot","dot","dog","lot","log","cog"
        "hot","dot","dog","lot","log"
    };
    Solution solution;
    solution.ladderLength("hit", "cog", words);
    // solution.ladderLength("qa", "sq", words);
}