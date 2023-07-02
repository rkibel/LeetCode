#include <sstream>
using namespace std;

class Problem7 {
public:
    int reverse(int x) {
        bool neg = x < 0;
        stringstream a;
        a << x;
        string s = a.str();
        ::reverse(s.begin(), s.end());
        stringstream b(s);
        int res = 0;
        b >> res;
        if (res == INT_MAX)
            return 0;
        neg ? res *= -1 : res*= 1;
        return res;
    }
};