#include <string>
using namespace std;

class Problem389 {
public:
    char findTheDifference(string s, string t) {
        for (int i = 0; i < t.length(); i++){
            if (s.find(t[i]) == string::npos) return t[i];
            s.erase(s.begin() + s.find(t[i]));
        }
        return ' ';
    }
};