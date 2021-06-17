class Solution(object):
    def movesToMakeZigzag(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        l = len(nums)
        ret1 = 0
        ret2 = 0
        
        for i in range(l):
            if i % 2 == 0:
                # nums[0] < nums[1]
                if i == 0:
                    if l != 1:
                        ret1 += max(nums[0]-nums[1]+1, 0)
                elif i == l-1:
                    ret1 += max(nums[l-1]-nums[l-2]+1, 0)
                else:
                    ret1 += max(nums[i]-min(nums[i-1], nums[i+1])+1, 0)
            else:
                # nums[0] > nums[1]
                if i == l-1:
                    ret2 += max(nums[l-1]-nums[l-2]+1, 0)
                else:
                    ret2 += max(nums[i]-min(nums[i-1], nums[i+1])+1, 0)

        return min(ret1, ret2)