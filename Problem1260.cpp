#include <vector>
using namespace std;

class Problem1260 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        vector<vector<int>> cp(grid);
        int m = grid.size(), n = grid[0].size();
        k = m*n - k % (m*n);
        for (int i = 0; i < m; i++) for (int j = 0; j < n; j++)
                grid[i][j] = cp[(i+(j+k)/n) % m][(j+k) % n];
        return grid;
    }
};