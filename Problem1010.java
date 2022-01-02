class Problem1010 {
    public int numPairsDivisibleBy60(int[] time) {
        int[] rems = new int[60];
        int res = 0;
        for (int t: time){
            res += (t%60 == 0) ? rems[0] : rems[60-t%60];
            rems[t%60]++;
        }
        return res;
    }
}