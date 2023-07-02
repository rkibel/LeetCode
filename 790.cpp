#include<vector>
using namespace std;

class Problem790 {
public:
    int numTilings(int n) {
        vector<int> ans(n+4);
        ans[1] = 1;
        ans[2] = 2;
        ans[3] = 5;
        int mod = static_cast<int>(pow(10, 9)) + 7;
        for (int i = 4; i < ans.size(); i++){
            ans[i] = (2*ans[i-1]) % mod + ans[i-3];
            ans[i] %= mod;
        }
        return ans[n];
    }
};