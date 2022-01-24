#include <string>
using namespace std;

class Problem242 {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        int letters[255] = {};
        for (int i = 0; i < s.length(); i++) letters[t[i]]++, letters[s[i]]--;
        for (int let: letters) if (let != 0) return false;;
        return true;
    }
};