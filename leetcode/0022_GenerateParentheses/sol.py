class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        return self.dfs(n)
    
    def dfs(self, n):
        if n == 1:
            return ['()']
        
        hashMap = {}
        ret = []
        ss = self.dfs(n-1)
        for s in ss:
            for i in range((n-1)*2):
                sNew = s[:i] + '()' + s[i:]
                if sNew not in hashMap:
                    hashMap[sNew] = True
                    ret.append(sNew)
                    
        return ret