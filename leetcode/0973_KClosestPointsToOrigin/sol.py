# solving by quickSelecting
# however, it can also be solved by heap
class Solution(object):
    def kClosest(self, points, K):
        """
        :type points: List[List[int]]
        :type K: int
        :rtype: List[List[int]]
        """            
        return self.quickSelect(points, K)

    def quickSelect(self, points, K):
        pivot = self.getDistance(points[0])
        bigger = []
        smaller = []
        equal = []
        for i in range(len(points)):
            if self.getDistance(points[i]) > pivot:
                bigger.append(points[i])
            elif self.getDistance(points[i]) < pivot:
                smaller.append(points[i])
            else:
                equal.append(points[i])
                
        if len(smaller) < K:
            smaller = smaller + equal
        
        if len(smaller) == K:
            return smaller
        elif len(smaller) < K:
            return smaller + self.quickSelect(bigger, K-len(smaller))
        else:
            return self.quickSelect(smaller, K)
        
                
    
    def getDistance(self, point):
        return point[0]**2 + point[1]**2