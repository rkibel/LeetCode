public class Problem416 {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for (int i: nums) sum += i;
        if (sum % 2 == 1) return false;
        sum /= 2;
        boolean[] p = new boolean[sum+1];
        p[0] = true;
        for (int j : nums)
            for (int i = sum; i > 0; i--)
                if (i >= j) p[i] = p[i] || p[i-j];
            
        return p[sum];
    }
}