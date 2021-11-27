#include "vector"
#include <algorithm>
using namespace std;

class Problem53 {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums[0];
        int curr = nums[0];
        for (int i = 1; i < nums.size(); i++){
            (curr + nums[i] > nums[i]) ? curr+= nums[i] : curr = nums[i];
            m = max(m, curr);
        }
        return m;
    }
};