class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # dp[i]: the largetest sum in num[:i+1]
        dp = []
        ret = 0
        for i in range(len(nums)):
            if i == 0:
                s = nums[0]
                dp.append(s)
                ret = s

            else:
                s = max(dp[i-1]+nums[i], nums[i])
                dp.append(s)
                ret = max(ret, s)
        
        return ret