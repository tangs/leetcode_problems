#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need, window;
        for (char ch: s1) need[ch]++;
        
        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char ch = s2[right++];
            if (need.count(ch)) {
                if (++window[ch] == need[ch]) {
                    if (++valid == need.size()) return true;
                } else if (window[ch] > need[ch]) {
                    char ch1;
                    do {
                        ch1 = s2[left++];
                        if (window[ch1]-- == need[ch1]) --valid;
                    } while (ch != ch1);
                }
            } else {
                window.clear();
                valid = 0;
                left = right;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    solution.checkInclusion(
        "vuocwszndxhpilvfujnmakne",
        "vxivzcmyxxvvlchcnbirwatjuloyulmrwfiknxqhkclnubtxbxmkngxtauarrbaxnbpobwvsvzvitycqfrpulnmivncjuxxhntxpmiuojvbfsfdwjbqdiymwbvxlrrxedtdhnyrxyijtlzwirpnfqsooedatollvosgutcxidziubcgrwxskketqaxqslfrhybltsmjyshjopblwszlcibvgvwkabrwqhjunjbjqgguxjupxphldyrzmjazqpdsxmljdxfzutgbxddrpkzkcaosuyouszqdvlrjpzywrompedzyxvvvwglftjvaxrjgfztaqxqfxgjtvmsplsvjzyizywglfcsknmpvaagetggcjzpjoklpmzvfqxlryziuggyrdcrbcgepvnwovfgtiqxgjqkvlukzcmminsghqqkzydfabvpkuegaoprkufbuoqvectqpvtunjxtdjhteoakweecnaocvsllbwrotxcigtwoehqpvalqwuhmsbdngocfnewhyypfmhfllpvcjllaqefpcyypsuevxokcujejhydbfgyinjlwhiuecpzvjmttlvxasgfpetprrbiumeroptqhfsbqrxfhvkbsecuimklqjmbvicelsxglbdctbbsxhmklwcmntodsoutdtesawojotnqfjnwbvhbbescbllmjwevqxandaxpiqscqhwcyulrxukjbdismrhhyvuwzphuvcderanzzkfqoxjcclornlkmatzpapttbkjnsjpmqyaoznrudwtqfjsnnyhhclcentngrjhaxyocmkdeobotrcjlofqdchcarwtjvwhjwnpkvvidmnfzluuxseacnomprtwpwrpkjknlagdcjhglenkmuunalbmgvjaijnasegddfsydyamgjgaujqwehbhxniwhgljshdcmhgqrjyoyltajgdxerxoqdbgrpxgriquhkextrlfhrmpkqkcwoyfwcszztdicqruwilxzqdmiggfagkacbpglqwijgohwxggfjfkmvozkzihitcniooezootwebkntcpgvhikdapbyxwfgjvhsboxodnedpcoiqndeasbyryoxetfygqqnfwikejcrgrqmeffxgcskzeyhpedjsxxxfvqjrklsdczmdhrnfnyjrukzxgqpgtxeswxqlczcfhvypkvosdutpidivzixunwynhwaizruqnnozghmwinjazrkmghdmrwmgvcaerbfwphsmiyjutsjnlgcmdsutwffxojyszaxgawjyypboztzqpjijcsqgtaavsduwjqexwhxkazaejgkchxentxjwpnjfauddhafdbqznbcfzquohewtfzdmwpcdhjxrtcduxmuuracdwkrqkbreiuoubqirjgoxkrejvoyrzmvoxpxsagkyggqesprqrtvbnptoqpmfgitkpzfchqlotdccryzwbnmyieufdhshlaycrfszvipkdlwsfntnqszftlbcoxusavav");
}