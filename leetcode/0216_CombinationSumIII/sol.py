# dp(k, maxNum, n) = dp(k-1, maxNum-1, n-maxNum) + dp(k, maxNum-1, n)
class Solution(object):
    def combinationSum3(self, k, n):
        """
        :type k: int
        :type n: int
        :rtype: List[List[int]]
        """
        return self.dfs(k, 9, n)
        
    def dfs(self, k, maxNum, n):                
        if k == 1:
            if maxNum >= n:
                combination = [n]
                return [combination]
            else:
                return []
        
        if maxNum == 0:
            return []
        
        combinations_ret = []
        if n > maxNum:        
            combinations = self.dfs(k-1, maxNum-1, n-maxNum)
            for combination in combinations:
                combination.append(maxNum)
                combinations_ret.append(combination)
        
        combinations = self.dfs(k, maxNum-1, n)
        combinations_ret += combinations
        
        return combinations_ret
                
        