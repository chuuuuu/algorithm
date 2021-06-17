# without cahce(map) the time complexity is O(n^3)
# with cache(for isPld) can reduce to O(n^2)

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        self.sMap = {}
        self.pldMap = {}
        ret = self.dfs(s)
        return ret
        
    def dfs(self, s):
        if s == "":
            return 0
        if s in self.sMap:
            return self.sMap[s]
        
        count = self.dfs(s[:-1])
        
        c = s[-1]
        for i in range(len(s)):
            if self.isPld(s[i:-1]+c):
                count += 1
        
        self.sMap[s] = count
        return count
    
    def isPld(self, s):
        if len(s) == 0 or len(s)==1:
            return True
        if s in self.pldMap:
            return self.pldMap[s]

        flag = False
        if s[0] == s[-1]:
            flag = self.isPld(s[1:-1])
        self.pldMap[s] = flag

        return flag