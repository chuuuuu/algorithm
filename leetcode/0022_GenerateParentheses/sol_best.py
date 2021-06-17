# hard to write with dp
# however, i can split '()' into '(' and ')'
# dp(l, r) means there are l '(' and r ')'

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.map = {}
        return self.dfs(n, n)
    
    def dfs(self, l, r):
        if l == 1 and r == 0:
            return ['(']
        
        if (l, r) in self.map:
            return self.map[(l, r)]

        ret = []
        
        if r > 0:
            ss = self.dfs(l, r-1)

            for s in ss:
                ret.append(s+')')

        if l > r:
            ss = self.dfs(l-1, r)

            for s in ss:
                ret.append(s+'(')
        
        self.map[(l, r)] = ret
        
        return ret