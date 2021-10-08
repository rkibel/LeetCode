class Problem79 {
    static boolean found = false;
    static int loc = 0;
    public boolean exist(char[][] board, String word) {
        if (word.equals("")) // final condition
            found = true;
        else if (loc == 0){ //first condition
            loc++;
            for (int i = 0; i < board.length; i++){
                for(int j = 0; j < board.length; j++){
                    if (board[i][j] == word.charAt(0)){
                        board[i][j] = '0';
                        found = found || exist(board, word.substring(1));
                    }
                }
            }
        }
        else{
            for (int i = 0; i < board.length; i++){
                for (int j = 0; j < board[i].length; j++){
                    if (board[i][j] == '0'){
                        board[i][j] = '1';
                        if (i != board.length-1 && (board[i+1][j] != '0' && board[i+1][j] != '1')){
                            board[i+1][j] = '0';
                            found = found || exist(board, word.substring(1));
                        }
                        if (i != 0 && (board[i-1][j] != '0' && board[i-1][j] != '1')){
                            board[i-1][j] = '0';
                            found = found || exist(board, word.substring(1));
                        }
                        if (j != board.length-1 && (board[i][j+1] != '0' && board[i][j+1] != '1')){
                            board[i][j+1] = '0';
                            found = found || exist(board, word.substring(1));
                        }
                        if (j != 0 && (board[i][j-1] != '0' && board[i][j-1] != '1')){
                            board[i][j-1] = '0';
                            found = found || exist(board, word.substring(1));
                        }
                    }
                }
            }
        }
        return found;
    }
}