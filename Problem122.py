class Problem122(object):
    def maxProfit(self, prices):
        memo = dict()
        
        while(prices[-1] == 0):
            prices.pop();
        
        def getMax(start, sell):
            if start == len(prices):
                return 0
            
            if sell * start in memo:
                return memo[sell * start]
            
            maxProfit = 0
            for i in range(start, len(prices)):
                next = i+1
                
                if sell == -1:
                    while next < len(prices) and prices[next] <= prices[i]:
                        next += 1
                    
                profit = sell * prices[i] + getMax(next, -1 * sell)
                
                if profit > maxProfit:
                    maxProfit = profit
                    
            memo[sell * start] = maxProfit
            
            return maxProfit
        
        return getMax(0, -1)