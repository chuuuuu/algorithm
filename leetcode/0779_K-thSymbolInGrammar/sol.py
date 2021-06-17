# 0 -> 01
# 1 -> 10

# 0 -> 01 -> 0110 -> 01101001 -> 0110100110010110
# 11 -> ~(11-8) -> ~~(3-2)
class Solution:
    def kthGrammar(self, N: int, K: int) -> int:
        flag = True
        while K>2:
            n = 1
            while n < K:
                n = n << 1
            n = n >> 1
            K = K - n
            flag = not flag
            
        if K == 1:
            if flag:
                return 0
            else:
                return 1
        else: 
            # K == 2
            if flag:
                return 1
            else:
                return 0