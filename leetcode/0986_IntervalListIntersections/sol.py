class Solution(object):
    def intervalIntersection(self, firstList, secondList):
        """
        :type firstList: List[List[int]]
        :type secondList: List[List[int]]
        :rtype: List[List[int]]
        """
        
        ptr1 = 0
        ptr2 = 0
        
        start_ret = 0
        end_ret = 0
        
        ret = []
        
        while True:
            if ptr1 == len(firstList) or ptr2 == len(secondList):
                break
            
            interval = self.merge(firstList[ptr1], secondList[ptr2])
            if interval != None:
                ret.append(interval)
            
            if firstList[ptr1][1] > secondList[ptr2][1]:
                ptr2 += 1
            elif firstList[ptr1][1] < secondList[ptr2][1]:
                ptr1 += 1
            else:
                ptr1 += 1
                ptr2 += 1
        
        return ret
                
    def merge(self, interval1, interval2):
        x0 = max(interval1[0], interval2[0])
        x1 = min(interval1[1], interval2[1])
        
        if x1 >= x0:
            return [x0, x1]
        else:
            return None