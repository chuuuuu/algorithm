class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        upper = l-1
        lower = 0
        
        # [0, 1, 2]
        # [1, 2, 0]
        # [2, 0, 1]
        while True:
            idx = (upper + lower) // 2

            if nums[idx] > nums[lower]:
                lower = idx
            elif nums[idx] < nums[lower]:
                upper = idx
            
            if idx == (upper + lower) // 2:
                if upper == l-1:
                    if nums[-1] > nums[0]:
                        return nums[0]
                    else:
                        return nums[-1]
                else:
                    return nums[upper]


