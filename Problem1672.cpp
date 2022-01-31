#include <algorithm>
#include <vector>
using namespace std;

class Problem1672 {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = 0;
        for (int i = 0; i < accounts.size(); i++){
            int curr = 0;
            for (int j = 0; j < accounts[i].size(); j++) curr += accounts[i][j];
            m = max(m, curr);
        }
        return m;
    }
};