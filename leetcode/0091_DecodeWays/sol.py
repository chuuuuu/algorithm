class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.hashMap = {}
        return self.dfs(s)
        
    def dfs(self, s):
        if s in self.hashMap:
            return self.hashMap[s]
        
        if len(s) == 0:
            self.hashMap[s] = 1
            return 1
        
        ret = 0
        if self.check(s[-1:]):
            ret += self.dfs(s[:-1])

        if len(s) > 1:
            if self.check(s[-2:]):
                ret += self.dfs(s[:-2])

        self.hashMap[s] = ret
        return ret
    
    def check(self, s):
        if s[0] == '0':
            return False
        
        n = int(s)
        if 0 < n and n < 27:
            return True
        
        return False