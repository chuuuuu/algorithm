class Solution(object):
    def findMaximumXOR(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        trie = Trie()
        for num in nums:
            trie.insert(num)
            
        ret = 0
        for num in nums:
            ret = max(ret, trie.findMaxXor(num))
        
        return ret
            
        
        
class Trie():
    def __init__(self):
        self.root = Node(None)
        
    def insert(self, num):
        n = self.root
        for i in range(32):
            bit = (num >> (31-i)) & 1
            n = n.insert(bit)
            
        n.setEnd()
    
    def findMaxXor(self, num):
        ret = 0
        n = self.root
        for i in range(32):
            bit = (num >> 31-i) & 1
            if n.nodes[bit^1] != None:
                ret = ret << 1
                ret = ret ^ 1
                n = n.nodes[bit^1]
            else:
                ret = ret << 1
                n = n.nodes[bit]
                
        return ret
            
        
        
        
class Node():
    def __init__(self, bit):
        self.bit = bit
        self.isEnd = False
        self.nodes = [None, None]
    
    def insert(self, bit):
        if self.nodes[bit] == None:
            self.nodes[bit] = Node(bit)
        
        return self.nodes[bit]

    def setEnd(self):
        self.isEnd = True