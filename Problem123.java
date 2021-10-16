public class Problem123 {
    int profit;
    public int maxProfit(int[] prices) {
        profit = maxTransaction(prices, 0, prices.length-1);
        int index1 = 0;
        int index2 = 2;
        //index2 must be >2 away from index1
        if (prices.length > 4){
            for (int i = index1; i <= prices.length - 5; i++){
                //for (int j = i + 2; )
                
                
                
            }
            
            
            
            
            
        }
        return profit;
    }
    public int maxTransaction(int[] prices, int index1, int index2){
        int m = 0;
        for (int i = index1; i < index2; i++){
            for (int j = i; j < index2 + 1; j++){
                m = Math.max(m, prices[j] - prices[i]);
            }
        }
        return m;
    }
}
