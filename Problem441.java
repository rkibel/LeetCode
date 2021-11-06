class Problem441 {
    public int arrangeCoins(int n) {
        int counter = 1;
        while (n > 0){
            if (n - counter < 0)
                return counter-1;
            n -= counter;
            counter++;
        }
        return counter -1;
    }
}