# https://leetcode.com/problems/next-permutation/
# coding=utf-8

class Solution(object):
    def nextPermutation(self, nums):
        # 1 2 3 4
        # 1 2 4 3
        # 1 3 2 4
        # 1 3 4 2
        # 1 4 2 3
        # 1 4 3 2
        # 2 1 3 4
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        # 數字從最後面開始往回看
        # 檢查有無持續變大
        # 直到變小時，將其與後面數字中最略大於他的數字做交換
        # 接著把後面的數字做排序
        # 若全部都檢查完了，將其排成最小序列
        for i in range(len(nums)):
            if i == len(nums)-1:
                nums.sort()
                break
                
            if nums[-1-i-1] < nums[-1-i]:
                minNum = 101
                minNumIdx = 0
                for j in range(i+1):
                    if nums[-1-j] > nums[-1-i-1]:
                        if nums[-1-j] < minNum:
                            minNum = min(nums[-1-j], minNum)
                            minNumIdx = -1-j
                        
                nums[-1-i-1], nums[minNumIdx] = nums[minNumIdx], nums[-1-i-1]
                nums[-1-i:] = sorted(nums[-1-i:])
                break
        
        return nums
