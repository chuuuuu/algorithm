class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        ptrs = []
        for i in range(k):
            ptrs.append(i+1)
            
        rets = []        
        stopFlag = False
        #ptrs: [1, 3, 4]
        #k: 3
        #p1: 2
        while True:
            ret = []
            for i in range(k):
                ret.append(ptrs[i])
            rets.append(ret)
            
            p1 = 0
            while True:
                if ptrs[k-1-p1] == n-p1:
                    if p1 == k-1:
                        stopFlag = True
                        break
                    p1 += 1
                else:
                    break
            
            if stopFlag:
                break
            
            ptrs[k-1-p1] += 1
            for i in range(p1):
                ptrs[k-p1+i] = ptrs[k-1-p1+i] + 1
                    
        return rets
            