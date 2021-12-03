#include <vector>
#include <algorithm>
using namespace std;

class Problem152 {
public:
    int maxProduct(vector<int>& nums) {
        int m = INT_MIN;
        for (int i = 0; i < nums.size(); i++){
            int curr = nums[i];
            m = max(m, curr);
            for (int j = i+1; j < nums.size(); j++){
                curr *= nums[j];
                m = max(m, curr);
            }
        }
        return m;
    }
};