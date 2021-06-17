# we want 
# 1@1@1=0
# 1@0=1
# we can use numbers to save bit state(to represent how many times the operation made)
# in this case we need to store 3 state for each bits
# hence we need two number, a and b
# (0, 0) means 0
# (1, 0) means 1
# (0, 1) means 2
# (0, 0) means 0
# and we know the theory that 
# we can build the logical statement with only [and, or, not]
# hence, we can build the truth table for a, b, num, a', b'
# where, a' and b' are the state after operation
# and now we can try to make the logical statement with only [and, or, not]

'''
Here's the truth table i bluit
a  b  n  a' b'
0  0  0  0  0
0  0  1  1  0
1  0  0  1  0
1  0  1  0  1
0  1  0  0  1
0  1  1  0  0
'''
class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a, b = 0, 0
        for num in nums:
            c = a
            a = (~a&~b&num)|(a&~b&~num)
            b = (c&~b&num)|(~c&b&~num)

        return a