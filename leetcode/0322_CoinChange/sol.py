class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        
        # [1 4 5], 8
        # i should return 2
        # dynamic programming
        # approach1 Top down
        inf = amount
        ret = self.dfs(coins, amount, inf)
        if ret > inf:
            return -1
        
        return ret
        
    def dfs(self, coins, amount, inf):
        if amount==0:
            return 0
        if amount<0:
            return 2*inf
        
        ret = 2*inf
        for i in range(len(coins)):
            num = self.dfs(coins, amount - coins[i], inf) + 1
            ret = min(ret, num)
        
        return ret

s = Solution()
s.coinChange([1, 2, 5], 1)