class Solution:
    def canPartitionKSubsets(self, nums, k):
        s = sum(nums)
        if s % k != 0:
            return False
        
        s = s // k
        sums = [s] * k
        nums.sort()
        nums.reverse()
        return self.canPartition(nums, sums)

    def deepCopy(self, arr):
        if not isinstance(arr, list):
            return arr
        
        ret = []
        for emt in arr:
            ret.append(self.deepCopy(emt))
            
        return ret
    
    # return whether nums can be partition into sums
    def canPartition(self, nums, sums):
        if len(sums) == 1:
            return sum(nums) == sums[0]
        
        isDone = {}
        num = nums[0]
        for i in range(len(sums)):
            if sums[i] in isDone:
                continue
                
            new_sums = self.deepCopy(sums)
            if num == new_sums[i]:
                new_sums.pop(i)
                if self.canPartition(nums[1:], new_sums):
                    return True

            elif num < new_sums[i]:
                new_sums[i] = new_sums[i] - num
                if self.canPartition(nums[1:], new_sums):
                    return True
            
            isDone[sums[i]] = True
            
        return False