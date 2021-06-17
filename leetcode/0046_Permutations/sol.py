class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.dfs(nums)
        
    def dfs(self, nums):
        if len(nums) == 0:
            return [[]]
        
        combinations_ret = []
        combinations = self.dfs(nums[:-1])
        for combination in combinations:
            for i in range(len(combination)):
                combination_ret = combination[:i] + [nums[-1]] + combination[i:]
                combinations_ret.append(combination_ret)
            combination.append(nums[-1])
            combinations_ret.append(combination)    
        
        return combinations_ret