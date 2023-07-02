#include <vector>
#include <string>
using namespace std;

class Problem228 {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> vec;
        if (nums.size() == 0) return vec;
        string a = to_string(nums[0]), b = a;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] != nums[i-1]+1){
                (a==b) ? vec.push_back(a) : vec.push_back(a + "->" + b);
                a = to_string(nums[i]);
            }
            b = to_string(nums[i]);
        }
        (a==b) ? vec.push_back(a) : vec.push_back(a + "->" + b);
        return vec;
    }
};