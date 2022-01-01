#include <vector>
#include <algorithm>
using namespace std;

class Problem121 {
public:
    int maxProfit(vector<int>& prices) {
        int m = INT_MAX, p = 0;
        for (int& i: prices) p = max(p, i-m), m = min(m, i);
        return p;
    }
};