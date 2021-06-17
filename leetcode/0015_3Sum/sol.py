import json

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ret = []
        retMap = {}
        twoSumSMap = {}
        for i in range(len(nums)):
            s = -nums[i]
            if s not in twoSumSMap:
                twoSumAnss = self.twoSum(nums[:i]+nums[i+1:], s)
                twoSumSMap[s] = True
                for j in range(len(twoSumAnss)):
                    twoSumAnss[j].append(nums[i])
                    twoSumAnss[j].sort()
                    ans = twoSumAnss[j]
                    if json.dumps(ans) not in retMap:
                        retMap[json.dumps(ans)] = True
                        ret.append(ans)
        return ret
    
    def twoSum(self, nums, s):
        ret = []
        retMap = {}
        numMap = {}
        for i in range(len(nums)):
            if s - nums[i] in numMap:
                ans = [s-nums[i], nums[i]]
                ans.sort()
                if json.dumps(ans) not in retMap:
                    retMap[json.dumps(ans)] = True
                    ret.append(ans)

            numMap[nums[i]] = True
            
        return ret

s = Solution()
s.threeSum([-1,0,1,2,-1,-4])