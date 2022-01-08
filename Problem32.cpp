#include <algorithm>
#include <string>
using namespace std;

class Problem32 {
public:
    int longestValidParentheses(string s) {
        int open = 0, close = 0, MAX = 0;
        for (int i = 0; i < s.length(); i++){
            (s[i] == '(') ? open++ : close++;
            if (open == close) MAX = max(MAX, open*2);
            else if (close > open) open = close = 0;
        }
        
        open = close = 0;
        
        for (int i = s.length()-1; i >= 0; i--){
            (s[i] == '(') ? open++ : close++;
            if (open == close) MAX = max(MAX, open*2);
            else if (open > close) open = close = 0;
        }
        
        return MAX;
    }
};