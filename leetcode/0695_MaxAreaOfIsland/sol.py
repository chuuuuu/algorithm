import collections

class Solution(object):
    def maxAreaOfIsland(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        self.grid = grid
        self.isVisited = {}
        queue = collections.deque()
        posArr = []
        m = len(self.grid)
        n = len(self.grid[0])
        for i in range(m):
            for j in range(n):
                if self.grid[i][j] == 1:
                    posArr.append((i, j))
                    
        ret = 0
        while len(posArr) != 0:
            current_pos = posArr.pop()
            if current_pos in self.isVisited:
                continue
            queue.append(current_pos)
            self.isVisited[current_pos] = True
            
            area = 0
            while len(queue) != 0:
                current_pos = queue.popleft()
                area += 1
                for pos in self.getNeighbours(current_pos):
                    queue.append(pos)
                    self.isVisited[pos] = True
            
            ret = max(ret, area)
                
        return ret
        
    def getNeighbours(self, pos):
        m = len(self.grid)
        n = len(self.grid[0])
        ds = [[-1, 0], [1, 0], [0, -1], [0, 1]]
        ret = []
        for d in ds:
            x = pos[0] + d[0]
            y = pos[1] + d[1]
            if x < 0 or x >= m or y < 0 or y >= n:
                continue
            if (x, y) in self.isVisited:
                continue
            if self.grid[x][y] == 0:
                continue
            
            ret.append((x, y))
            
        return ret
        
        