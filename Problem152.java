class Problem152 {
    public int maxProduct(int[] nums) {
        int MAO = nums[0], mio = nums[0], mao = nums[0];
        for (int i = 1; i < nums.length; i++){
            if (nums[i] < 0){
                int temp = mio;
                mio = mao;
                mao = temp;
            }
            mio = Math.min(nums[i], mio*nums[i]);
            mao = Math.max(nums[i], mao*nums[i]);
            MAO = Math.max(MAO, mao);
        }
        return MAO;
    }
}