# dp[i, j] = max(dp[i, j-1], dp[i-1, j], {dp[i-1, j-1] + 1, if s[i-1]=s[j-1]})

class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        
        m = len(text1)
        n = len(text2)
        dp = []
        for i in range(m+1):
            dp.append([])
            for j in range(n+1):
                dp[-1].append(0)
                
        for i in range(m+1):
            for j in range(n+1):
                if i != 0 and j!= 0:
                    if text1[i-1] == text2[j-1]:
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]+1)       
                    else:
                        dp[i][j] = max(dp[i][j-1], dp[i-1][j], dp[i-1][j-1])
                        
        return dp[-1][-1]