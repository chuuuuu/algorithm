# https://leetcode.com/problems/spiral-matrix/
import json

class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        arrivedMap = {}
        pt = [0, 0]
        ds = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        dsIdx = 0
        count = 0
        m = len(matrix)
        n = len(matrix[0])
        ptNum = m*n
        ret = []
        
        while True:
            arrivedMap[json.dumps(pt)] = True
            ret.append(matrix[pt[0]][pt[1]])
            count += 1
            if count == ptNum:
                break
                
            newPt = [pt[0]+ds[dsIdx][0], pt[1]+ds[dsIdx][1]]
            if json.dumps(newPt) in arrivedMap or newPt[0]>=m or newPt[0]<0 or newPt[1]>=n or newPt[1]<0:
                dsIdx = (dsIdx+1) % 4
                newPt = [pt[0]+ds[dsIdx][0], pt[1]+ds[dsIdx][1]]
            
            pt = newPt
        
        return ret