#include <vector>
using namespace std;
class Problem134 {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tot = 0, curr = 0, index = 0;
        for (int i = 0; i < gas.size(); i++){
            tot += gas[i]-cost[i], curr += gas[i]-cost[i];
            if (curr < 0) curr = 0, index = i+1;
        }
        return (tot < 0) ? -1 : index;
    }
};