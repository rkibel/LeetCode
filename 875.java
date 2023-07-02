class Problem875 {
    public int minEatingSpeed(int[] piles, int h) {
        int max = piles[0];
        for (int pile: piles) max = Math.max(max, pile);
        return findSpeed(piles, 1, max, h);
    }
    public int findSpeed(int[] piles, int left, int right, int h){
        if (left >= right) return right;
        int mid = left + (right-left)/2, hours = 0;
        for (int pile: piles) hours += (pile+mid-1)/mid;
        return (hours > h) ? findSpeed(piles, mid+1, right, h) : findSpeed(piles, left, mid, h);
    }
}