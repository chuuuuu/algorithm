# time complexity: O(k^n)
# get all possible partitions, then check

import json
# since k and len(nums) are small, i want to go dfs with k

# [1, 2, 3]: subet
# [subet, subet]: partition
# [partition, partition]: partitions
class Solution:
    def canPartitionKSubsets(self, nums, k):
        s = sum(nums)
        if s % k != 0:
            return False
        
        s = s // k
        self.hashMap = {}
        partitions = self.getPartitions(nums, k)
        for partition in partitions:
            if self.check(partition, s):
                return True
            
        return False
    
    def check(self, partition, s):
        for subset in partition:
            if sum(subset) != s:
                return False
        
        return True
    
    def deepCopy(self, arr):
        if not isinstance(arr, list):
            return arr
        
        ret = []
        for emt in arr:
            ret.append(self.deepCopy(emt))
            
        return ret
    
    def getPartitions(self, nums, k):
        numsEncode = json.dumps(nums)
        if numsEncode in self.hashMap:
            partitions = self.hashMap[numsEncode]
            return self.deepCopy(partitions)
        
        if len(nums) == 0:
            partition = []
            for i in range(k):
                subset = []
                partition.append(subset)
            
            partitions = [partition]
            self.hashMap[numsEncode] = partitions
            return self.deepCopy(partitions)

        ret_partitions = []
        for i in range(k):
            partitions = self.getPartitions(nums[:-1], k)
            for partition in partitions:
                subset_i = partition[i]
                subset_i.append(nums[-1])
            
            ret_partitions += partitions
        
        self.hashMap[numsEncode] = ret_partitions
        return self.deepCopy(ret_partitions)