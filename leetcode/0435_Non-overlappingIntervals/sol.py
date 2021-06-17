class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort(key=lambda interval: interval[0])
        
        i1 = None
        i2 = None
        ret = 0
        for interval in intervals:
            if i1 == None:
                i1 = interval
            else:
                i2 = interval
                if i2[0] < i1[1]:
                    ret += 1
                    if i1[1] > i2[1]:
                        i1 = i2
                else:
                    i1 = i2
                        
        return ret