class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        moves = []
        for i in range(m + 1):
            moves.append([])
            for j in range(n + 1):
                moves[-1].append(0)
                
        moves[1][1] = 1
                
        for i in range(1, m+1):
            for j in range(1, n+1):
                if i != 1 or j != 1:
                    moves[i][j] = moves[i-1][j] + moves[i][j-1]
               
        return moves[-1][-1]