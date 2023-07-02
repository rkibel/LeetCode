#include <vector>
#include <queue>
using namespace std;

class Problem210 {
public:
    vector<int> findOrder(int num, vector<vector<int>>& P) {
        vector<vector<int>> G(num);
        vector<int> ans, degree(num);
        for (auto& pre: P)
            G[pre[1]].push_back(pre[0]), degree[pre[0]]++;
        
        queue<int> q;
        for (int i = 0; i < num; i++)
            if (degree[i] == 0) q.push(i);
        
        while(size(q)){
            auto cur = q.front();
            q.pop(), ans.push_back(cur);
            for (auto next: G[cur])
                if (--degree[next] == 0) q.push(next);
        }
        
        if (size(ans) == num) return ans;
        return {};
    }
};