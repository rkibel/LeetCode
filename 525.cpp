#include <unordered_map>
#include <algorithm>
using namespace std;

class Problem525 {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> map = {{0, -1}};
        int len = 0, sum = 0;
        
        for (int i = 0; i < nums.size(); i++){
            (nums[i] == 0) ? sum-- : sum++;
            (map.count(sum)) ? len = max(len, i-map[sum]) : map[sum] = i;
        }
        
        return len;
    }
};