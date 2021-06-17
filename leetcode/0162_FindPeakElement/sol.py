# https://leetcode.com/problems/find-peak-element/
# coding=utf-8

class Solution(object):
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 當看到array中搜尋東西時，最快的方法就是用binary search
        # 可以觀察到每一個上坡都會有peak element
        # 因此可以利用這點來縮小範圍
        ret = self.search(nums, 0, len(nums)-1)
        return ret

    def search(self, nums, x, y):
        if x+1 == y:
            if self.isPeak(nums, x):
                return x
            elif self.isPeak(nums, y):
                return y

        pos = (x+y)//2
        if self.isPeak(nums, pos):
            return pos
        elif nums[pos+1] > nums[pos]:
            return self.search(nums, pos, y)
        else:
            return self.search(nums, x, pos)

    def isPeak(self, nums, x):
        if len(nums) == 1:
            return True

        elif x == 0:
            if nums[0] > nums[1]:
                return True
            else:
                return False
        
        elif x == len(nums)-1:
            if nums[-1] > nums[-2]:
                return True
            else:
                return False

        else:
            if nums[x] > nums[x+1] and nums[x] > nums[x-1]:
                return True
            else:
                return False

s = Solution()
s.findPeakElement([1,2,3,1])