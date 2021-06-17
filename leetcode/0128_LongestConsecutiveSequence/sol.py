# of course, i can sort the array, and find the ans in O(nlogn)
# however, it will be faster, if we use hash

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        myMap = {}
        for num in nums:
            myMap[num] = False
        
        ret = 0
        counter = 0
        for num in nums:
            if myMap[num]:
                continue

            myMap[num] = True
            counter = 1
            next_num = num+1
            while True:
                if next_num in myMap:
                    myMap[next_num] = True
                    counter += 1
                    next_num += 1
                else:
                    break
                    
            prev_num = num-1
            while True:
                if prev_num in myMap:
                    myMap[prev_num] = True
                    counter += 1
                    prev_num -= 1
                else:
                    break
                    
            ret = max(ret, counter)
                    
            
        return ret
        