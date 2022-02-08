#include <vector>
using namespace std;

class Problem283 {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        for (int i = len-1; i >= 0; i--) 
            if (nums[i] == 0) nums.erase(nums.begin()+i), nums.push_back(0);
    }
};