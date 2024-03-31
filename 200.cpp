#include <vector>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    counter++;
                    visitPoint(grid, i, j);
                }
            }
        }
        return counter;
    }
    void visitPoint(vector<vector<char>>& grid, int i, int j){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') return;
        grid[i][j] = '2';
        visitPoint(grid, i+1, j);
        visitPoint(grid, i-1, j);
        visitPoint(grid, i, j+1);
        visitPoint(grid, i, j-1);
    }
};