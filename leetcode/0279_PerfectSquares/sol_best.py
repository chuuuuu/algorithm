# bottom-up dp is better than top-down dp if i can do it with bottom-up

class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        # dp[n] = min(dp[n-i2]+1, for all i s.t. n-i2>=0)
        dp = [[None]]*(n+1)
        for i in range(n+1):
            print(i, len(dp))
            dp[i] = i
            for j in range(int(i**0.5)+1):
                j2 = j * j
                dp[i] = min(dp[i], dp[i - j2]+1)
        
        return dp[n]

s= Solution()
