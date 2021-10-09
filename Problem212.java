import java.util.*;
public class Problem212 {
    public List<String> findWords(char[][] board, String[] words) {
        List<String> output = new ArrayList();
        for (String word: words){
            if (exist(board, word))
                output.add(word);
        }
        return output;
    }
    public boolean exist(char[][] board, String word){
        int m = board.length, n = board[0].length;

        if (m == 0 || n == 0 || word.length() == 0) 
            return false; 
        for (int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if (board[i][j] == word.charAt(0) && DFS(board, word, i, j, 0, new boolean[m][n]))
                    return true;
            }
        }
        return false;
    }
    
    public boolean DFS (char [][] board,String word, int i, int j, int wordIndex, boolean [][] looked){
        int m = board.length, n = board[0].length;
        if (wordIndex == word.length()) 
            return true; 
        
        if (i < 0 || j < 0 || i >= m || j >= n || word.charAt(wordIndex) != board[i][j] || looked[i][j]) 
            return false;
            
        looked[i][j] = true;
        if (DFS(board, word, i-1, j, wordIndex+1, looked) || 
            DFS(board, word, i+1, j, wordIndex+1, looked) || 
            DFS(board, word, i, j-1, wordIndex+1, looked) ||
            DFS(board, word, i, j+1, wordIndex+1, looked))
            return true;
        looked[i][j] = false;
        return false;
    }
}
