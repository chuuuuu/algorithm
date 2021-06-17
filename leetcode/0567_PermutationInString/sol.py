class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if len(s1) == 0:
            return True
        
        sMap = {}
        for c in s1:
            if c not in sMap:
                sMap[c] = [0, 0] # [count in subS2, count in s1]
            
            sMap[c][1] += 1
            
        idx = 0
        count = 0
        exceed = 0
        while True:
            if idx == len(s2):
                return False
            
            c = s2[idx]
            if c not in sMap:
                idx += 1
                count = 0
                exceed = 0
                for key in sMap:
                    sMap[key][0] = 0
                    
            else:
                sMap[c][0] += 1
                count += 1
                if sMap[c][0] > sMap[c][1]:
                    exceed += 1
                        
                if count == len(s1):
                    if exceed > 0:
                        if sMap[s2[idx+1-count]][0] > sMap[s2[idx+1-count]][1]:
                            exceed -= 1
                            
                        sMap[s2[idx+1-count]][0] -= 1
                        count -= 1

                    else:
                        return True

                idx += 1