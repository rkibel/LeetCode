public class Problem123 {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        int [][] arr = new int[3][n]; //constructs a 3 by n array
        
        for (int i = 1; i <= 2; i++) { //cycles for the last two rows
            int mDiff = arr[i-1][0] - prices[0]; //mDiff is set to negative first value
            for (int j = 1; j < n; j++){
                arr[i][j] = Math.max(arr[i][j-1], prices[j] + mDiff); 
                //a value in the array is set to max of the number behind it, currentprice+maxDiff
                mDiff = Math.max(mDiff, arr[i-1][j] - prices[j]);
                //mDiff is set to max of itself, arr value above minus current price
            }
        }
        //result is in final row last element
        return arr[2][n-1];
        
    }
}
