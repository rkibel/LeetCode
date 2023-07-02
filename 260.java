class Problem260 {
    public int[] singleNumber(int[] nums) {
        int XOR = 0;
        for (int n: nums)
            XOR ^= n;
        int rightMostBit = XOR & -XOR;
        int num = 0;
        for (int n : nums)
            if ((n & rightMostBit) != 0)
                num ^= n;
        
        return new int[]{num, XOR ^ num};
    }
}