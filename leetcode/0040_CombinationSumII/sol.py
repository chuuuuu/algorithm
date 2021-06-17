class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates.sort()
        return self.dfs(candidates, target)
    
    def dfs(self, candidates, target):
        if sum(candidates) == target:
            combination = candidates
            combinations = [combination]
            return combinations
        
        if sum(candidates) < target:
            combinations = []
            return combinations

        [[1, 2, 3, 4, 7, 7, 7, 7, 7, 7, 7], 14]
        idx = -1
        while True:
            if -idx == len(candidates):
                break
                
            if candidates[idx-1] == candidates[-1]:
                idx -= 1
            else:
                break
                
        combinations_ret = self.dfs(candidates[:idx], target)
        
        if target >= candidates[-1]:
            combinations = self.dfs(candidates[:-1], target-candidates[-1])
            for combination in combinations:
                combination.append(candidates[-1])
                combinations_ret.append(combination)
                            
        return combinations_ret