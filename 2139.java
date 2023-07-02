class Problem2139 {
    public int minMoves(int target, int maxDoubles) {
        int counter = 0;
        while (target != 1){
            if (maxDoubles > 0 && target % 2 ==0){
                target /= 2;
                maxDoubles--;
            }
            else if (maxDoubles <= 0) return counter + (target-1);
            else target--;
            counter++;
        }
        return counter;
    }
}