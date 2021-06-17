# dp[i] = dp[i-nums[j]] for j in range(len(nums))
class Solution(object):
    def combinationSum4(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        dp = []
        l = len(nums)
        for i in range(target+1):
            dp.append(0)
        
        dp[0] = 1
        
        for i in range(target+1):
            for j in range(l):
                if i >= nums[j]:
                    dp[i] += dp[i-nums[j]]
                    
        return dp[-1]