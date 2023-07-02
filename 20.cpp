#include <stack>
using namespace std;

class Problem20 {
public:
    bool isValid(string s) {
        stack<char> ha;
        for (int i = 0; i < s.length(); i++){
            char c = s[i], top = (ha.empty()) ? NULL : ha.top();
            if (c == '(' || c == '[' || c == '{') ha.push(c);
            else if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) ha.pop();
            else return false;
        }
        return ha.empty();
    }
};