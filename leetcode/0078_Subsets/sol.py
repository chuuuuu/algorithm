class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        
        ret = [[]]
        for i in range(len(nums)):
            for j in range(len(ret)):
                copyArr = []
                for k in range(len(ret[j])):
                    copyArr.append(ret[j][k])

                copyArr.append(nums[i])
                ret.append(copyArr)
                
        return ret