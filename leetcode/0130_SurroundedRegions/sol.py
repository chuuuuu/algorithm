class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        self.m = len(board)
        self.n = len(board[0])
        self.pts = []
        for i in range(self.m):
            for j in range(self.n):
                flag = self.dfs(board, i, j)
                self.draw(board, flag)

        return board
    
    def dfs(self, board, x, y):
        if self.isOutOfBoard(x, y):
            return True
        
        if board[x][y] == 'X':
            return True

        if board[x][y] == '?':
            return True
        
        board[x][y] = '?'
        self.pts.append([x, y])
                
        flag = True if not self.isBorder(x, y) else False
        flag = self.dfs(board, x-1, y) and flag
        flag = self.dfs(board, x+1, y) and flag
        flag = self.dfs(board, x, y-1) and flag
        flag = self.dfs(board, x, y+1) and flag
        
        return flag
        
    def isBorder(self, x, y):
        if x == 0 or x == self.m-1 or y ==0 or y ==self.n-1:
            return True
        
        return False
    
    def isOutOfBoard(self, x, y):
        if x < 0 or x > self.m-1 or y <0 or y > self.n-1:
            return True
        
        return False
    
    def draw(self, board, flag):
        c = 'X' if flag else 'O'
        for pt in self.pts:
            board[pt[0]][pt[1]] = c
            
        self.pts = []
            