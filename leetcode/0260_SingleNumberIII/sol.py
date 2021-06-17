class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # s = a ^ b
        s = 0
        for num in nums:
            s ^= num
            
        mask = 1
        for i in range(32):
            if s & 1 == 1:
                mask = 1 << i
                break
            else:
                s = s >> 1
        
        ret = [0, 0]
        for num in nums:
            if num & mask == mask:
                ret[0] ^= num
            else:
                ret[1] ^= num
                
        return ret