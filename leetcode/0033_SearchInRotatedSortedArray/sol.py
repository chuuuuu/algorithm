class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 1:
            if target == nums[0]:
                return 0
            else:
                return -1
        
        lower = 0
        upper = len(nums)-1
        l = (lower + upper) // 2
        # [0, 1, 2]
        # [1, 2 ,0]
        # [2, 0, 1]
        while True:
            if upper == lower + 1:
                if upper == len(nums)-1:
                    if nums[-1] > nums[0]:
                        l = 0
                    else:
                        l = len(nums)-1
                else:
                    l = upper
                    
                break

            if nums[l] > nums[lower]:
                lower = l
                l = (lower + upper) // 2
            else:
                upper = l
                l = (lower + upper) // 2
        
        lower = 0
        upper = len(nums)-1
        ret = 0
        if target >= nums[lower]:
            if lower == l:
                ret = self.binarySearch(nums, lower, len(nums)-1, target)
            else:
                ret = self.binarySearch(nums, lower, l-1, target)
        else:
            ret = self.binarySearch(nums, l, upper, target)
            
        return ret
    
    def binarySearch(self, nums, lower, upper, target):
        if lower == upper:
            if nums[lower] == target:
                return lower
            else:
                return -1
            
        l = (lower + upper) // 2
        while True:
            if target == nums[l]:
                return l
            
            if lower+1 == upper:
                if nums[lower] == target:
                    return lower
                
                if nums[upper] == target:
                    return upper
                
                return -1
            
            if target < nums[l]:
                upper = l
                l = (lower + upper) // 2
                
            else:
                lower = l
                l = (lower + upper) // 2