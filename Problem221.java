class Problem221 {
    public int maximalSquare(char[][] matrix) {
        for (int size = Math.min(matrix.length, matrix[0].length); size >= 1; size--){
            for (int i = 0; i < matrix.length; i++){
                for (int j = 0; j < matrix[0].length; j++){
                    if (isFull(matrix, i, j, size)) return size*size;
                }
            }
        }
        return 0;
    }
    public boolean isFull(char[][] matrix, int itopleft, int jtopleft, int size){
        if (itopleft + size > matrix.length || jtopleft + size > matrix[0].length) 
            return false;
        for (int i = itopleft; i < itopleft + size; i++){
            for (int j = jtopleft; j < jtopleft + size; j++){
                if (matrix[i][j] == '0') return false;
            }
        }
        return true;
    }
}