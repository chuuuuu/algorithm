# 3 cases
# 1. rob nums[0], but not nums[-1] & nums[1]
# 2. rob nums[-1], but not nums[0] & nums[-2]
# 3. neither rob nums[0], nor nums[-1]

# dp_rob[i] = dp_skip[i-1] + nums[i]
# dp_skip[i] = max(dp_rob[i-1], dp_skip[i-1])


class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        
        if n < 3:
            return max(nums)
        
        best = [0, 0, 0]
        
        # case1
        dp_rob = []
        dp_skip = []
        for i in range(n):
            dp_rob.append(0)
            dp_skip.append(0)
            
        for i in range(2, n-1):
            dp_rob[i] = dp_skip[i-1] + nums[i]
            dp_skip[i] = max(dp_rob[i-1], dp_skip[i-1])
            
        best[0] = max(dp_rob[-2], dp_skip[-2]) + nums[0]
        
        # case2
        dp_rob = []
        dp_skip = []
        for i in range(n):
            dp_rob.append(0)
            dp_skip.append(0)
            
        for i in range(1, n-2):
            dp_rob[i] = dp_skip[i-1] + nums[i]
            dp_skip[i] = max(dp_rob[i-1], dp_skip[i-1])
            
        best[1] = max(dp_rob[-3], dp_skip[-3]) + nums[-1]

        # case3
        dp_rob = []
        dp_skip = []
        for i in range(n):
            dp_rob.append(0)
            dp_skip.append(0)
            
        for i in range(1, n-1):
            dp_rob[i] = dp_skip[i-1] + nums[i]
            dp_skip[i] = max(dp_rob[i-1], dp_skip[i-1])
            
        best[2] = max(dp_rob[-2], dp_skip[-2])

        return max(best)