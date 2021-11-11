class Problem1413 {
    public int minStartValue(int[] nums) {
        int minSum = nums[0];
        int sum = nums[0];
        int index = 0;
        for (int i = 1; i < nums.length; i++){
            sum += nums[i];
            if (sum <= minSum){
                minSum = sum;
                index = i;
            }
        }
        return (1 - minSum <= 0) ? 1 : 1-minSum;
    }
}