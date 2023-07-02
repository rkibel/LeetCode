#include <algorithm>
#include <numeric>
using namespace std;

class Problem878 {
public:
    int nthMagicalNumber(int n, int a, int b) {
        long LCM = lcm(a, b), left = min(a, b), right = n*left, mid, res;
        auto magicLessEqual = [&](long x) {return x/a + x/b - x/LCM;};
        while (left <= right){
            mid = left + (right-left)/2;
            if (magicLessEqual(mid) < n) left = mid+1;
            else right = mid-1, res = mid;
        }
        return res % static_cast<int>(1e9+7);
    }
};