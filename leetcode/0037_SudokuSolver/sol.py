class Solution:
    def solveSudoku(self, board):
        """
        Do not return anything, modify board in-place instead.
        """
        boardAns = self.dfs(board)
        for i in range(9):
            for j in range(9):
                board[i][j] = boardAns[i][j]
        
    def deepCopy(self, arr):
        if not isinstance(arr, list):
            return arr
        
        ret = []
        for emt in arr:
            ret.append(self.deepCopy(emt))
            
        return ret

    # if it's solvable return board, else return None
    def dfs(self, board):
        pos = self.findSpot(board)
        if pos == None:
            return board
        
        for num in range(9):
            isLegal = self.isLegal(board, pos, num)
            if isLegal:
                boardCopy = self.deepCopy(board)
                boardCopy[pos[0]][pos[1]] = str(num+1)
                boardAns = self.dfs(boardCopy)
                if boardAns != None:
                    return boardAns
        
        return None
                
    
    # if there's spot('.') return pos, else return None
    def findSpot(self, board):
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    return [i, j]
        
        return None
    
    def isLegal(self, board, pos, num):
        for i in range(9):
            if board[pos[0]][i] == str(num+1):
                return False
            
        for i in range(9):
            if board[i][pos[1]] == str(num+1):
                return False
            
        # 0, 1, 2 -> 0
        i0 = pos[0] // 3 
        j0 = pos[1] // 3 
        
        for i in range(3):
            for j in range(3):
                if board[i0*3+i][j0*3+j] == str(num+1):
                    return False
                
        return True
        