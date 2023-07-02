class Pair<T,U> {
    private final T key;
    private final U value;

    public Pair(T key, U value) {
        this.key = key;
        this.value = value;
    }

    public T getKey() {
        return this.key;
    }

    public U getValue() {
        return this.value;
    }
}
class Problem994 {
    private int min = 0;
    public int orangesRotting(int[][] grid) {
        Pair<boolean[][], Integer> pair = rottenBoolArray(grid);
        int fresh = pair.getValue();
        if (fresh == 0) return min;
        for (int i = 0; i < grid.length; i++)
            for (int j = 0; j < grid[i].length; j++)
                if (grid[i][j] == 1 && rot(grid, pair.getKey(), i, j)) grid[i][j] = 2;
        if (fresh == rottenBoolArray(grid).getValue()) return -1;
        min++;
        return orangesRotting(grid);
    }
    public boolean rot(int[][]grid, boolean[][] b, int i, int j){
        return (i > 0 && b[i-1][j] && grid[i-1][j] == 2) ||
        (i < grid.length-1 && b[i+1][j] && grid[i+1][j] == 2) ||
        (j > 0 && b[i][j-1] && grid[i][j-1] == 2) ||
        (j < grid[i].length-1 && b[i][j+1] && grid[i][j+1] == 2);
    }
    public Pair<boolean[][], Integer> rottenBoolArray(int[][]grid){
        boolean[][] rottenArray = new boolean[grid.length][grid[0].length];
        int num = 0;
        for (int i = 0; i < grid.length; i++){
            for (int j = 0; j < grid[i].length; j++){
                if (grid[i][j] == 2) rottenArray[i][j] = true;
                else if (grid[i][j] == 1) num++;
            }
        }
        return new Pair<>(rottenArray, num);
    }
}
