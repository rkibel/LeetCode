public class Problem279 {
    int m = Integer.MAX_VALUE;
    public int numSquares(int n) {
        numSq (n, 0);
        return m;
    }
    void numSq (int n, int counter){
        if (counter < m){
            if (n <= 1)
                m = Math.min(m, counter + n);
            else{
                for (int i = SQRT(n); i >= 1; i--){
                    //System.out.println(n);
                    int p = i*i;
                    numSq(n-p, counter+1);
                }
            }
        }
    }
    int SQRT (int num){
        return (int)(Math.sqrt(num));
    }
}
