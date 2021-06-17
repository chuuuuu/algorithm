# algorithm 1
# dp[n] = max(dp[i]+1, for all nums[i] < nums[n] & i < n)
# however, it cost O(n^2)

# algortihm 2
# [0, 3, 1, 6, 2, 3]
# l=1, 0
# l=2, 0, 3
# l=3, 0, 1
# l=4, 0, 1, 6
# l=5, 0, 1, 2
# l=6, 0, 1, 2, 3

class Solution(object):
    def lengthOfLIS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        self.mem = []
        for num in nums:
            self.insert(num)
        
        return len(self.mem)
    
    # if i can write it with quicksearch, it can reduce to O(log(n))
    def insert(self, num):
        usedFlag = False
        for i in range(len(self.mem)):
            if num <= self.mem[i]:
                self.mem[i] = num
                usedFlag = True
                break
                
        if not usedFlag:
            self.mem.append(num)

