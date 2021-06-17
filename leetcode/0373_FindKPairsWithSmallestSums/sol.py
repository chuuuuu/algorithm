# [1, 3, 5, 7]
# [2, 3, 4, 5]
import heapq

class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        n = len(nums1)
        m = len(nums2)
        if n == 0 or m == 0:
            return []
        
        heap = []
        ptrs = [0] * n
        for i in range(n):
            heapq.heappush(heap, (nums1[i] + nums2[ptrs[i]], i, ptrs[i]))
            
        ret = []
        while True:
            num, i, j = heapq.heappop(heap)
            ret.append([nums1[i], nums2[j]])
            if len(ret) == k or len(ret) == m*n:
                return ret

            if ptrs[i] != m-1:
                ptrs[i] += 1
                heapq.heappush(heap, (nums1[i]+nums2[ptrs[i]], i, ptrs[i]))