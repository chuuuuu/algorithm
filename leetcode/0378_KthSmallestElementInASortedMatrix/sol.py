# piority queue
# time complexity: O((n^2-k)log(n))
import heapq

class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        
        n = len(matrix)
        ptrs = [0] * n
        heap = []
        for i in range(n):
            heapq.heappush(heap, (-matrix[i].pop(), i))
            
        count = 0
        while True:
            num, idx = heapq.heappop(heap)
            count += 1
            if count == n**2 + 1 - k:
                return -num
            
            if len(matrix[idx]) != 0:
                heapq.heappush(heap, (-matrix[idx].pop(), idx))


