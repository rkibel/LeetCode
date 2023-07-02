#include <vector>
#include <queue>
using namespace std;

class Problem1046 {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (auto i: stones) pq.push(i);
        while (pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if (a != b) pq.push(a-b);
        }
        return pq.empty() ? 0 : pq.top();
    }
};