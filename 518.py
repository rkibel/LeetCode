class Solution(object):
    def change(self, amount, coins):
        dp = [0 for i in range(amount+1)]
        dp[0] = 1
        for coin in coins:
            for amt in range(coin, len(dp)):
                dp[amt] += dp[amt-coin]
        return dp[-1]