#include <vector>
using namespace std;

class Problem80 {
public:
    int removeDuplicates(vector<int>& nums) {
        bool dup = false;
        for (int i = nums.size()-1; i > 0; i--){
            if (nums[i] != nums[i-1]) dup = false;
            else{
                if (dup) nums.erase(nums.begin()+i-1);
                else dup = true;
            }
        }
        return nums.size();
    }
};