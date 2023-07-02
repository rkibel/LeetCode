public class Problem463 {
    public int islandPerimeter(int[][] grid) {
        int perim = 0;
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[0].length; j++){
                if (grid[i][j] == 1)
                    perim += numSides(grid, i, j);
                
            }
        }
        return perim;
    }
    public int numSides (int[][] grid, int i, int j){
        int res = 0;
        if (i == 0) res++;
        if (i == grid.length-1) res++;
        if (j == 0) res++;
        if (j == grid[0].length-1) res++;
        if (i != 0)
            if (grid[i-1][j] == 1) res++;
        if (i != grid.length-1)
            if (grid[i+1][j] == 1) res++;
        if (j != 0)
            if (grid[i][j-1] == 1) res++;
        if (j != grid[0].length-1)
            if (grid[i][j+1] == 1) res++;
        return res;
    }
}
