# it can run with O(n^(3/2)), but time limit exceeded
# it's dp top-down, which means that it need to make lots of function calls, which can make the process slow
# i'll try dp bottom-up

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        self.inf = n
        self.dp = {}
        ret = self.dfs(n)
        
        return ret
        
    def dfs(self, n):
        if n in self.dp:
            return self.dp[n]
        
        if n == 0:
            return 0
        
        leastNum = self.inf
        for i in range(n): # O(sqrt(n)), and might be called by n times
            i2 = (i+1)**2
            if i2 > n:
                break
            
            num = self.dfs(n - i2) + 1
            leastNum = min(leastNum, num)
                
        self.dp[n] = leastNum
        return leastNum
            