class Problem849 {
    public int maxDistToClosest(int[] seats) {
        int curr = 0;
        while(seats[curr] == 0) curr++;
        int maxDist = curr;
        for (int i = curr; i < seats.length; i++){
            if (seats[i] == 1){
                maxDist = Math.max(maxDist, (curr+1)/2);
                curr = 0;
            }
            else curr++;
        }
        maxDist = Math.max(maxDist, curr);
        return maxDist;
    }
}