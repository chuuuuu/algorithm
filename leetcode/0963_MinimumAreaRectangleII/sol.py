import json

class Solution(object):
    def minAreaFreeRect(self, points):
        """
        :type points: List[List[int]]
        :rtype: float
        """
        
        # to be rectangle,
        # a and b vectors need to be the same
        # c and d vectors need to be the same
        # a and c vectors need to be vertical
        # however, it take O(n^4), (the worst case can be O(n^8))
        
        # i can decide a rectangualr with 3 point
        # and i can find another point in O(1) with hashtable
        # hence, it can only take O(n^3)
        
        # however, i can decide whether abcd is a retangular with
        # ac's center is bd's center
        # ac's length is bd's length
        # it'll only take O(n^2)
        
        pMap = {}
        self.inf = 40000 * 40000 + 1
        minArea = self.inf
        for i in range(len(points)):
            for j in range(len(points)):
                c = [points[i][0]+points[j][0], points[i][1]+points[j][1]]
                l = (points[i][0]-points[j][0])**2+ (points[i][1]-points[j][1])**2
                s = json.dumps([c, l])
                if s in pMap:
                    for pts in pMap[s]:
                        area = self.getArea(pts[0], points[i], pts[1], points[j])
                        if area < minArea:
                            minArea = area
                    pMap[s].append([points[i], points[j]])
                else:
                    pMap[s] = [[points[i], points[j]]]
        
        if minArea >= self.inf:
            return 0

        return minArea
    
    def getArea(self, pt1, pt2, pt3, pt4):
        a = ((pt1[0]-pt2[0])**2 + (pt1[1]-pt2[1])**2)**0.5
        b = ((pt3[0]-pt2[0])**2 + (pt3[1]-pt2[1])**2)**0.5

        if a * b == 0:
            return self.inf 
        
        return a * b
        