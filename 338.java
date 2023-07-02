class Problem338 {
    public int[] countBits(int n) {
        int[] bits = new int[n+1];
        for (int i = 0; i <= n; i++)
            bits[i] = (int)(Integer.toBinaryString(i).chars().filter(ch -> ch == '1').count());
        return bits;
    }
}