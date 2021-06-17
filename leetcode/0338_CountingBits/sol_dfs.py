# 0
# 1: 1
# 10: 1
# 11: 2
# 100: 1
# 101: 2
# 110: 2
# 111: 3
# 1000: 1
# 1->1,2->1,2,2,3

class Solution:
    def countBits(self, num: int) -> List[int]:        
        p = 0
        x = num
        while x != 0:
            p = p+1
            x = x >> 1
        
        return self.dfs(p)[:num+1]
            
    def dfs(self, p):
        if p == 0:
            return [0]
        
        else:
            ret = self.dfs(p-1)
            for i in range(len(ret)):
                ret.append(ret[i]+1)
            return ret