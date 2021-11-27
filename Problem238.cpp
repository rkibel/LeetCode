#include "vector"
using namespace std;

class Problem238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0;
        for (int i : nums){
            if (i == 0) zeros++;
        }
        vector<int> output;
        int product = 1;
        if (zeros == 0){
            for (int i : nums)
                product *= i;
            for (int i : nums)
                output.push_back(product / i);
        }
        else if (zeros == 1){
            for (int i : nums)
                if (i != 0) product *= i;
            for (int i = 0; i < nums.size(); i++)
                nums[i] == 0 ? output.push_back(product) : output.push_back(0);
        }
        else{
            for (int i : nums)
                output.push_back(0);
        }
        
        return output;
    }
};