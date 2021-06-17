import json

class Solution(object):
    def subsetsWithDup(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        self.subsetMap = {}
        return self.dfs(nums)
        
    def deepCopy(self, arr):
        if not isinstance(arr, list):
            return arr
        
        ret = []
        for item in arr:
            ret.append(self.deepCopy(item))
            
        return ret
    
    def dfs(self, nums):
        if len(nums) == 0:
            subset = []
            subsets = [subset]
            return subsets
        
        ret = []
        subsets = self.dfs(nums[:-1])
        ret += subsets

        for subset in subsets:
            subsetCopy = self.deepCopy(subset)
            subsetCopy.append(nums[-1])
            subsetCopyEncode = json.dumps(subsetCopy)
            if subsetCopyEncode not in self.subsetMap:
                self.subsetMap[subsetCopyEncode] = True
                ret.append(subsetCopy)

            
        return ret