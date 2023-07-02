#include <algorithm>
#include <string>
using namespace std;

class Problem1446 {
public:
    int maxPower(string s) {
        if (s.length() == 0) return 0;
        char c = s[0];
        int m = 1, curr = 1;
        for (int i = 1; i < s.length(); i++){
            if (s[i] == c){
                curr++;
                m = max(m, curr);
            }
            else curr = 1;
            c = s[i];
        }
        return m;
    }
};