#include <string>
using namespace std;
class Problem125 {
public:
    bool isPalindrome(string s) {
        string fro, rev;
        for (int i = 0; i < s.length(); i++)
            if (isalpha(s[i]) || isdigit(s[i])) 
                fro += tolower(s[i]), rev.insert(rev.begin(), tolower(s[i]));
        return fro == rev;
    }
};