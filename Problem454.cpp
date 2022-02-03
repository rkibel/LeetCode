#include <vector>
#include <unordered_map>
using namespace std;

class Problem454 {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int counter = 0;
        unordered_map<int, int> twosum;
        for (auto& i: nums3) for (auto& j: nums4) twosum[i+j]++;
        for (auto& i: nums1) for (auto& j: nums2) counter += twosum[-i-j];
        return counter;
    }
};