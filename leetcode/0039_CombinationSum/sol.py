class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        self.nums = candidates
        combinations = []
        packets = self.dfs(target)
        for packet in packets:
            combination, maxNum = packet
            combinations.append(combination)
            
        return combinations
    
    # packet = [combination, maxNum]
    def dfs(self, target):
        packets_ret = []
        for num in self.nums:
            # 3 = 5 - 2
            # 2 = 5 - 3
            # 0 = 5 - 5
            
            # 6 = 8 - 2
            # 5 = 8 - 3
            # 3 = 8 - 5
            subTarget = target - num
            if subTarget == 0:
                packets_ret.append([[num], num])
            elif subTarget >= num:
                packets = self.dfs(subTarget)
                for packet in packets:
                    combination, minNum = packet
                    if num <= minNum:
                        combination.append(num)
                        packets_ret.append([combination, num])
        
        return packets_ret