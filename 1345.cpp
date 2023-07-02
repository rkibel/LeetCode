#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

class Problem1345 {
    public:
        int minJumps(vector<int>& arr) {
            if (arr.size() == 1) return 0;
            unordered_map <int, vector<int>> map;
            for (int i = 0; i < arr.size(); i++) map[arr[i]].push_back(i);
            
            int step = 0;
            queue<int> q;
            q.push(0);
            while(!q.empty()){
                step++;
                int size = q.size();
                for (int i = 0; i < size; i++){
                    int j = q.front(); q.pop();
                    if (j-1 >= 0 && map.find(arr[j-1]) != map.end()) q.push(j-1);
                    if (j+1 <= arr.size()-1 && map.find(arr[j+1]) != map.end()){
                        if (j+1 == arr.size()-1) return step;
                        q.push(j+1);
                    }
                    if (map.find(arr[j]) != map.end()){
                        for (auto k: map[arr[j]]){
                            if (k != j){
                                if (k == arr.size()-1) return step;
                                q.push(k);
                            }
                        }
                    }
                    map.erase(arr[j]);
                }
            }
            return step;
        }
    };