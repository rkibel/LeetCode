public class Problem40 {
    public int climbStairs(int n) {
        if (n <= 1)
            return 1;
        int[] stair = new int[n+1];
        stair[0] = 1;
        stair[1] = 1;
        for (int i = 2; i < stair.length; i++){
            stair[i] = stair[i-1] + stair[i-2];
        }
        return stair[n];
    }
    /* you can also use recursion
    if (n > 2)
        return climbStairs(n-1) + climbStairs(n-2)
    runtime in this case is incredibly slow
    */
}
