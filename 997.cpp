#include <vector>
using namespace std;

class Problem997 {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> vec(n+1);
        for (auto t: trust) vec[t[0]]--, vec[t[1]]++;
        for (int i = 1; i < vec.size(); i++) if (vec[i] == n-1) return i;
        return -1;
    }
};