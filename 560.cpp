#include <unordered_map>
#include <vector>
using namespace std;

class Problem560 {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int counter = 0, curr = 0;
        for (auto& i: nums){
            curr += i;
            if (curr == k) counter++;
            counter += map[curr-k];
            map[curr]++;
        }
        return counter;
    }
};