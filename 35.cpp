#include "vector"
using namespace std;

class Problem35 {
public:
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
    int binarySearch(vector<int>nums, int beg, int end, int target){
        int mid = beg + (end-beg)/2;
        if (nums[mid] == target)
            return mid;
        else if (beg >= end){
            if (nums[beg] > target)
                return beg;
            return beg + 1;
        }
        else if (nums[mid] < target){
            return binarySearch(nums, mid+1, end, target);
        }
        else{
            return binarySearch(nums, beg, mid-1, target);
        }
    }
};