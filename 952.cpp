#include "vector"
#include <algorithm>
#include <numeric>
#include <unordered_map>
using namespace std;

class UnionFinder {
    public:
        vector<int> a, b;
        UnionFinder(int n): a(n), b(n, 1){
            iota(a.begin(), a.end(), 0);
        }

        int find(int x){
            if (a[x] == x)
                return x;
            return a[x] = find(a[x]);
        }

        bool Union(int x, int y){
            int xp = find(x), yp = find(y);
            if (xp == yp)
                return false;
            if (b[xp] > b[yp]){
                a[yp] = a[xp];
                b[xp] += b[yp];
            }
            else{
                a[xp] = a[yp];
                b[yp] += b[xp];
            }
            return true;
        }
};


class Problem952 {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        UnionFinder uf (n+1);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++){
            int curr = nums[i];
            if (curr % 2 == 0){
                map[2].push_back(i);
                while(curr % 2 == 0)
                    curr >>= 1;
            }
            
            for (int p = 3; p <= sqrt(curr); p += 2){
                if (curr % p == 0){
                    map[p].push_back(i);
                    while (curr % p == 0)
                        curr /= p;
                }
            }
            
            if (curr > 1)
                map[curr].push_back(i);
        }
        
        for (auto& [prime, ids] : map){
            for (int i = 0; i < ids.size() - 1; i++)
                uf.Union(ids[i], ids[i+1]);
        }
        return *max_element(begin(uf.b), end(uf.b));
    }
    
};
