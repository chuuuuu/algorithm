import json

class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        m = len(board)
        n = len(board[0])
        for i in range(m):
            for j in range(n):
                ret = self.dfs(board, i, j, 0, word, {})
                if ret:
                    return True
        
        return False
    
    def dfs(self, board, x, y, idx, word, visitedMap):        
        print(x, y, idx)
        if json.dumps([x, y]) in visitedMap or board[x][y] != word[idx]:
            return False
        
        visitedMapCopy = visitedMap.copy()
        visitedMapCopy[json.dumps([x, y])] = True
        idx = idx + 1
        
        if idx == len(word):
            return True

        flag = False

        if x > 0:
            pt = [x-1, y]
            flag = flag or self.dfs(board, pt[0], pt[1], idx, word, visitedMapCopy)
                    
        if x < len(board)-1:
            pt = [x+1, y]
            flag = flag or self.dfs(board, pt[0], pt[1], idx, word, visitedMapCopy)

        if y > 0:
            pt = [x, y-1]
            flag = flag or self.dfs(board, pt[0], pt[1], idx, word, visitedMapCopy)

        if y < len(board[0])-1:
            pt = [x, y+1]
            flag = flag or self.dfs(board, pt[0], pt[1], idx, word, visitedMapCopy)

        return flag

s = Solution()
s.exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], "ABCCED")
            
        
        
        