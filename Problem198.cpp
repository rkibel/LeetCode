#include <vector>
#include <algorithm>
using namespace std;

class Problem98 {
    public:
        int rob(vector<int>& nums) {
            int a = nums[0], b = 0, c = 0;
            for (int i = 1; i < nums.size(); i++){
                c = max(a, b);
                a = b + nums[i];
                b = c;
            }
            return max(a, b);
        }
};

/*class Problem198 {
    private:
        int monay = 0;
    public:
        int rob(vector<int>& nums) {
            findMax(nums, 0, 0);
            return monay;
        }
        //brute force solution
        void findMax(vector<int> nums, int index, int currSum){
            if (nums.size() == 1){
                monay = nums[0];
                return;
            }
            if (nums.size() == 2){
                monay = max(nums[0], nums[1]);
                return;
            }
            if (index > nums.size()-1){
                monay = max(monay, currSum);
                return;
            }
            int val = nums.at(index);
            if (index == nums.size()-2 || index == nums.size()-1){
                monay = max(monay, currSum + val);
            }
            else{
                findMax(nums, index+1, currSum);
                findMax(nums, index+2, currSum + val);
                findMax(nums, index+3, currSum + val);
            }
        }
};
*/