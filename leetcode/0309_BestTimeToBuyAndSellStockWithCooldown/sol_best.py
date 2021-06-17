# dp_buy[i] = max(0, dp_sold[i-1]) - prices[i]
# dp_sell[i] = max(dp_buy[i-1], dp_hold[i-1]) + prices[i]
# dp_hold[i] = max(dp_hold[i-1], dp_buy[i-1])
# dp_sold[i] = max(dp_sold[i-1], dp_sell[i-1])
# dp_cool[i] = dp_sell[i-1]

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        if n == 0:
            return 0
        
        dp_buy = []
        dp_sell = []
        dp_hold = []
        dp_sold = []
        for i in range(n):
            dp_buy.append(-prices[i])

        for i in range(n):
            if i == 0:
                dp_hold.append(float('-inf'))
            else:
                dp_hold.append(max(dp_hold[i-1], dp_buy[i-1]))
            
        for i in range(n):
            if i == 0:
                dp_sell.append(float('-inf'))
            else:
                dp_sell.append(max(dp_buy[i-1], dp_hold[i-1]) + prices[i])
            
        for i in range(n):
            if i < 2:
                dp_sold.append(float('-inf'))
            else:
                dp_sold.append(max(dp_sold[i-1], dp_sell[i-1]))            
            
        for i in range(3, n):
            dp_buy[i] = max(0, dp_sold[i-1]) - prices[i]
            dp_sell[i] = max(dp_buy[i-1], dp_hold[i-1]) + prices[i]
            dp_hold[i] = max(dp_hold[i-1], dp_buy[i-1])
            dp_sold[i] = max(dp_sold[i-1], dp_sell[i-1])
                
        return max(0, dp_sell[-1], dp_sold[i])