# state of day: sell, cooling, other
# dp_other[i] = max(dp_other[i-1], dp_sell[i-2], dp_cooling[i-1])
# dp_sell[i] = stock[i] - stock[j] + max(dp_other[j-1], dp_cooling[j-1])
# dp_cooling[i] = dp_sell[i-1]

# dp_other[i] = max(dp_other[i-1], dp_sell[i-2])
# dp_sell[i] = stock[i] - stock[j] + max(dp_other[j-1], dp_sell[j-2])

# recursive by using function call
# slower than compute directly

class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        n = len(prices)
        self.prices = prices
        self.dpOther = []
        self.dpSell = []
        for i in range(n):
            self.dpOther.append(None)
            self.dpSell.append(None)
            
        ret = max(self.getDPOther(n-1), self.getDPSell(n-1), self.getDPSell(n-2))
        return ret
    def getDPOther(self, i):
        if i < 3:
            return 0
        
        if self.dpOther[i] != None:
            return self.dpOther[i]
        
        self.dpOther[i] = max(self.getDPOther(i-1), self.getDPSell(i-2))
        return self.dpOther[i]    
    
    def getDPSell(self, i):
        if i < 1:
            return 0
        
        if self.dpSell[i] != None:
            return self.dpSell[i]

        maxVal = 0
        for j in range(i):
            val = self.prices[i] - self.prices[j] + max(self.getDPOther(j-1), self.getDPSell(j-2))
            maxVal = max(val, maxVal)

        self.dpSell[i] = maxVal
        return self.dpSell[i]


