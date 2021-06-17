class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits) == 0:
            return []
        
        self.myMap = {
            '2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z'],
        }
        
        return self.dfs(digits)
        
    def dfs(self, digits):
        if len(digits) == 0:
            return [""]
        
        ret = []
        ss = self.dfs(digits[:-1])
        for s in ss:
            for c in self.myMap[digits[-1]]:
                ret.append(s+c)
                
        return ret
            