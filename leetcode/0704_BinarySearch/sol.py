class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        
        l = len(nums)
        upper = l-1
        lower = 0
        idx = (upper + lower) // 2
        while True:
            if upper < lower + 2:
                if nums[lower] == target:
                    return lower
                elif nums[upper] == target:
                    return upper                
                else:
                    return -1

            if nums[idx] == target:
                return idx
            elif nums[idx] < target:
                lower = idx
                idx = (upper + lower) // 2
            elif nums[idx] > target:
                upper = idx
                idx = (upper + lower) // 2