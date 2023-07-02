#include <vector>
using namespace std;

class Problem39 {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
        vector<int> temp;
        solve(0, cand, temp, target);
        return res;
    }
    
    void solve(int i, vector<int>& cand, vector<int>& temp, int target){
        if (target == 0){
            res.push_back(temp);
            return;
        }
        if (target < 0 || i == cand.size()) return;
        
        solve(i+1, cand, temp, target);
        
        temp.push_back(cand[i]);
        solve(i, cand, temp, target - cand[i]);
        temp.pop_back();
    }
};