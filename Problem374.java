/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

public class Problem374 extends GuessGame {
    int marker = 0;
    int upper;
    int lower = 1;
    int g;
    public int guessNumber(int n) {
        if (marker == 0){
            marker++;
            upper = n;
            g = n;
        }
        if (GuessGame.guess(g) == 0) 
            return g;
        else { //the guess is too small or too big
            g = (lower + upper)/2;
            switch(GuessGame.guess(g)){
                case 0: return g;
                case 1: lower = (upper + lower)/2 + 1; return guessNumber(g);
                case -1: upper = (upper + lower)/2; return guessNumber(g);
            }
        }  
        return -1;
    }
}

