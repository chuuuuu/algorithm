class Solution(object):
    def mincostTickets(self, days, costs):
        """
        :type days: List[int]
        :type costs: List[int]
        :rtype: int
        """
        # dp[i] is the cost spent from day i to the end of the day
        # dp[i] = min(dp[i-1]+cost[0], dp[i-7]+cost[1], dp[i-30]+cost[2])
        self.nextTravelDay = {}
        daysIdx = 0
        for i in range(365):
            if i+1 > days[daysIdx]:
                if daysIdx+1 == len(days):
                    break
                daysIdx += 1

            self.nextTravelDay[i+1] = days[daysIdx]

        self.dfsStartMap = {}
        inf = max(costs[0], costs[1], costs[2]) << 10
        costs = [[costs[0], 1], [costs[1], 7], [costs[2], 30]]
        ret = self.dfs(days, costs, 1, inf)
        return ret
        
    def dfs(self, days, costs, start, inf):
        if start in self.dfsStartMap:
            return self.dfsStartMap[start]
        if start > days[-1]:
            return 0
        
        ret = inf
        for i in range(3):
            end = start+costs[i][1]
            if end in self.nextTravelDay and self.nextTravelDay[start] == self.nextTravelDay[end]:
                ret = min(ret, self.dfs(days, costs, end, inf))
            else:
                ret = min(ret, self.dfs(days, costs, end, inf)+costs[i][0])
        
        self.dfsStartMap[start] = ret
        return ret