#include <string>
using namespace std;

class Problem520 {
public:
    bool detectCapitalUse(string word) {
        bool rule1 = false, rule2 = rule1, rule3 = rule2;
        isupper(word[0]) ? rule1 = true, rule3 = true : rule2 = true;
        for (int i = 1; i < word.length(); i++) isupper(word[i]) ? rule2 = false, rule3 = false : rule1 = false;
        return rule1 || rule2 || rule3;
    }
};