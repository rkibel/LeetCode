public class Problem279 {
        public int numSquares(int n) {
            return numSq (n, 0);        
        }
        int numSq (int n, int counter){
            if (n == 0)
                return counter;
            if (n == 1)
                return counter+1;
            else{
                for (int i = 0; Math.pow(i, 2) <= counter; i++){
                    int p = i*i;
                    numSq(n-p, counter+1);
                }
            }
            return 0;
        }
}
