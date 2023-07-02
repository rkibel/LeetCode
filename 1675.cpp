#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Problem1675 {
public:
    int minimumDeviation(vector<int>& nums) {
        int MAX = INT_MIN, MIN = INT_MAX;
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 1) nums[i] *= 2;
            MAX = max(MAX, nums[i]);
            MIN = min(MIN, nums[i]);
        }
        
        int minDev = MAX-MIN;
        priority_queue<int> q;
        for (int i: nums) q.push(i);
        while(q.top() % 2 == 0){
            int top = q.top();
            q.pop();
            
            minDev = min(minDev, top-MIN);
            top /= 2;
            MIN = min(MIN, top);
            q.push(top);
        }
        minDev = min(minDev, q.top()-MIN);
        return minDev;
    }
};