class Problem37 {
    char[][] BOARD;
    public void solveSudoku(char[][] board) {
        BOARD = board;
        solve();
        board = BOARD;
    }
    public boolean solve(){
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (BOARD[i][j] == '.'){
                    for (int c = 49; c < 58; c++){
                        if (valid(BOARD, i, j, (char)c)){
                            BOARD[i][j] = (char)c;
                            if (solve()) return true;
                            else BOARD[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    public boolean valid(char[][]board, int i, int j, char c){
        for (int I = 0; I < 9; I++){
            if (board[I][j] == c) return false;
            if (board[i][I] == c) return false;
            if (board[i/3*3 + I/3][j/3*3 + I%3] == c) return false;
        }
        return true;
    }
    
}