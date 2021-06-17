# time complexity: O(n^3)

class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) == 0:
            return 0
        if len(s) == 1:
            return 1

        ret = 0
        
        # if s[i] is center
        # s = "abcdefgh"
        # i = 3
        # s[i] = d
        for i in range(len(s)):
            for j in range(min(len(s)-i, i+1)):
                if s[i-j] == s[i+j]:
                    ret += 1
                else:
                    break
                
        # if s[i], s[i+1] is center
        for i in range(len(s)-1):
            for j in range(min(len(s)-i-1, i+1)):
                if s[i-j] == s[i+1+j]:
                    ret +=1
                else:
                    break
        
        return ret

