class Solution(object):
    def countBits(self, num):
        """
        :type num: int
        :rtype: List[int]
        """
        
        # 0: 0: 0
        # 1: 1: 1
        # 2: 10: 1
        # 3: 11: 2
        # 4: 100: 1
        # 5: 101: 2
        # 6: 110: 2
        # 7: 111: 3
        # 8: 1000: 1
        # 9: 1001: 2
        # 10: 1010: 2
        # 11: 1011: 3
        # 12: 1100: 2
        # 13: 1101: 3
        # 14: 1110: 3
        # 15: 1111: 4
        
        # 1->
        # 1,2->
        # 1,2,2,3->
        # 1,2,2,3,2,3,3,4->etc...
        
        if num == 0:
            return [0]
        
        ret = [0, 1]
        mem = [1]
        breakFlag = False
        while True:
            if breakFlag:
                break
                
            l = len(mem)
            for i in range(l):
                if len(ret) > num:
                    breakFlag = True
                    break
                ret.append(mem[i])

            for i in range(l):
                if len(ret) > num:
                    breakFlag = True
                    break
                ret.append(mem[i]+1)
                mem.append(mem[i]+1)

        return ret
        