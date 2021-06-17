# f(n, k) = f(n-1, k) + f(n-1, k-1)

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        return self.dfs(n, k)
        
    def dfs(self, n, k):
        if k == 0:
            return [[]]
        if n == k:
            ret = [[]]
            for i in range(n):
                ret[0].append(i+1)

            return ret
        
        # n, k > 1
        rets = self.dfs(n-1, k-1)
        for ret in rets:
            ret.append(n)

        if n > k:
            rets += self.dfs(n-1, k)
            
        return rets
            