# in 3sum, we fix one num, and use twoSum to find the other two num
# and we can use two pointer or hashTable to solve twoSum
# however, in 3sum closest, it's not valid to use hashTable

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        num = float('inf')
        for i in range(len(nums)-2):
            num_new = self.twoSumClosest(nums[i+1:], target - nums[i]) + nums[i]
            if self.abs(num_new, target) < self.abs(num, target):
                num = num_new

        return num
    
    def abs(self, n1, n2):
        return n1-n2 if n1>n2 else n2-n1
    
    def twoSumClosest(self, nums, target):
        i0 = 0
        i1 = len(nums)-1
        s = float('inf')

        while True:
            if i0 == i1:
                break

            s_new = nums[i0] + nums[i1]    
            if self.abs(s_new, target) < self.abs(s, target):
                s = s_new

            if s_new == target:
                break
            
            elif s_new > target:
                i1 = i1-1
                
            elif s_new < target:
                i0 = i0+1
                

        return s