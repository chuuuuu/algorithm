class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        
        counts = {}
        for num in nums:
            if num not in counts:
                counts[num] = 0
            counts[num] += 1
        
        maxCount = 0
        pairs = []
        for item in counts.items():
            num, count = item
            pairs.append([num, count])
            maxCount = max(maxCount, count)
            
        arrs = self.bucketSort(pairs, maxCount)
        ret = []
        while len(ret) != k:
            if len(arrs[-1]) == 0:
                arrs.pop()
            
            else:
                ret.append(arrs[-1].pop())
            
        return ret
        
    def bucketSort(self, pairs, upper):
        arrs = []
        for i in range(upper+1):
            arrs.append([])
            
        for pair in pairs:
            num, count = pair
            arrs[count].append(num)
            
        return arrs