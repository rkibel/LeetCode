class Problem849 {
    public int maxDistToClosest(int[] seats) {
        int curr = 0, maxDist = 0;
        for (int i = 0; i < seats.length; i++){
            if (seats[i] == 1){
                maxDist = Math.max(maxDist, (curr-1)/2);
                curr = 0;
            }
            else curr++;
        }
        maxDist = Math.max(maxDist, curr-1);
        return maxDist+1;
    }
}