# if odds: flase
# [8, 6, 4], s = 18, 18/2 = 9, find partition where partitino.sum = 9
# it can be done by dp
# dp[l][s] means if length = l, sum = n, it is possible to find partition?
# dp[l][s] = dp[l-1][s] | dp[l-1][s-nums[l]]

# since if dp[l][s]==True, then for any i>0, dp[l+i][s]==True
# we can reduce lots of computation

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        s = sum(nums)
        if s % 2 == 1:
            return False
        
        s = s // 2
        nums.sort()
        dp = []
        for i in range(len(nums)):
            dp.append([])
            for j in range(s+1):
                dp[i].append(False)
        
        for i in range(len(nums)):
            for j in range(s+1):
                if j == 0:                
                    dp[i][j] = True
                elif i == 0: 
                    # j != 0
                    dp[i][j] = False
                else:
                    dp[i][j] = dp[i-1][j]
                    if j >= nums[i]:
                        dp[i][j] = dp[i][j] or dp[i-1][j-nums[i]]
                        
        return dp[-1][-1]


