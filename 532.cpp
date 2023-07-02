#include <unordered_map>
#include <vector>
using namespace std;

class Problem532 {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto& i: nums) map[i]++;
        int counter = 0;
        for (auto& i: map){
            if (k == 0){
                if (i.second > 1) counter++;
            }
            else if (map.find(i.first + k) != map.end()) counter++;
        }
        return counter;
    }
};