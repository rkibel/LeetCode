class Problem1510 {
    int[]wins;
    public boolean winnerSquareGame(int n) {
        wins = new int[n+1];
        return winner(n);
    }
    public boolean winner(int n){
        if (n == 0) return false;
        for (int i = (int)Math.sqrt(n); i >= 1; i--){
            if (wins[n] == -1) return false;
            if (wins[n] == 1) return true;
            if (!winner(n-i*i)){
                wins[n] = 1;
                return true;
            }
        }
        wins[n] = -1;
        return false;        
    }
}