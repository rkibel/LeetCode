#include "vector"
using namespace std;

class Problem540 {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int left = 0, right = nums.size()-1, mid, num;
        while(left < right){
            mid = left + (right - left) / 2;
            num = (mid % 2 == 0) ? mid+1 : mid-1;
            if (nums[mid] == nums[num]) left = mid+1;
            else right = mid;
        }
        return nums[left];
    }
};