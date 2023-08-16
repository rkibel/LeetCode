#include <set>
#include <vector>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::multiset<int, std::greater<int> > s;
        std::vector<int> res;
        for (int i = 0; i < k; i++) s.insert(nums[i]);
        res.push_back(*(s.begin()));
        for (int j = k; j < nums.size(); j++) {
            s.erase(s.find(nums[j-k]));
            s.insert(nums[j]);
            res.push_back(*(s.begin()));
        }
        return res;
    }
};