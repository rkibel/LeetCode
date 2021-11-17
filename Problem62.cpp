#include <algorithm>
class Problem62 {
public:
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = std::min(m, n) - 1;
        
        double res = 1;
        for (int i = 1; i <= r; ++i, N--)
            res = res * N / i;
        
        return static_cast<int>(res);
    }
};