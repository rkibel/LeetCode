class Problem37 {
    List<Integer>[][]options;
    int[][] BOARD;
    public void solveSudoku(char[][] board) {
        options = new ArrayList[9][9];
        BOARD = new int[9][9];
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] != '.'){
                    BOARD[i][j] = (int)board[i][j] - 48;
                    options[i][j] = new ArrayList<>(Arrays.asList(BOARD[i][j]));
                }
                else{
                    options[i][j] = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7,8,9));
                }
            }
        }
        
        //for (int[] i: BOARD) System.out.println(Arrays.toString(i));
        System.out.println();
        int iterations = 0;
        while(iterations == 0 || update()){
            iterations++;
            for (int i = 0; i < 9; i++){
                for (int j = 0; j < 9; j++){
                    if (BOARD[i][j] == 0){
                        checkBox(i, j);
                        checkRow(i, j);
                        checkCol(i, j);
                    }
                }
            }
        }
        
        //for (int[] i: BOARD) System.out.println(Arrays.toString(i));
        for (List<Integer>[] i: options){
            for (List<Integer> j: i) System.out.print(j + " ");
            System.out.println();
        }
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                board[i][j] = (char)(BOARD[i][j]+48);
            }
        }
    }
    public void checkBox(int I, int J){
        List<Integer> singles = new ArrayList<>(Arrays.asList(1,2,3,4,5,6,7,8,9));
        for (int i = I/3 * 3; i < I/3*3+3; i++){
            for (int j = J/3 * 3; j < J/3*3+3; j++){
                if (i != I && j != J){
                    if (BOARD[i][j] != 0 && options[I][J].contains(BOARD[i][j]))
                        options[I][J].remove((Integer)BOARD[i][j]);
                    //for (Integer t: options[i][j])
                    //    if (singles.contains(t)) singles.remove(t);
                }
            }
        }
        if (singles.size() == 1) options[I][J] = singles;
    }
    public void checkRow(int I, int J){
        for (int j = 0; j < 9; j++){
            if (BOARD[I][j] != 0 && options[I][J].contains(BOARD[I][j])) options[I][J].remove((Integer)BOARD[I][j]);
        }
    }
    public void checkCol(int I, int J){
        for (int i = 0; i < 9; i++){
            if (BOARD[i][J] != 0 && options[I][J].contains(BOARD[i][J])) options[I][J].remove((Integer)BOARD[i][J]);
        }
    }
    public boolean update(){
        boolean doneSomething = false;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (BOARD[i][j] == 0 && options[i][j].size() == 1){
                    BOARD[i][j] = options[i][j].get(0);
                    doneSomething = true;
                }
            }
        }
        return doneSomething;
    }
}