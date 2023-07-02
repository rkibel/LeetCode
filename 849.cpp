#include <vector>
#include <algorithm>
using namespace std;

class Problem849 {
public:
    int maxDistToClosest(vector<int>& seats) {
        int curr = 0;
        while (seats[curr] == 0) curr++;
        int MAX = curr;
        for (int i = curr; i < seats.size(); i++) (seats[i] == 1) ? MAX = max(MAX, (curr+1)/2), curr = 0 : curr++;
        MAX = max(MAX, curr);
        return MAX;
    }
};