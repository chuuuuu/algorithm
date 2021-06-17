# https://leetcode.com/problems/container-with-most-water/

class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        getV = lambda x, y: height[y]*(y-x) if (height[x]>height[y]) else height[x]*(y-x)
        l = len(height)
        x, y = 0, l-1
        ret = getV(x, y)
        while x != y:
            if height[x] > height[y]:
                y -= 1
            else:
                x += 1
            
            v = getV(x, y)
            ret = v if v > ret else ret
        
        return ret