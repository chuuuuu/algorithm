"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

# use dictionary to store the information of node
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if head == None:
            return None
        
        nodeToIdx = {}
        node = head
        idx = 0
        while node != None:
            nodeToIdx[node] = idx
            node = node.next
            idx += 1
            
        n = idx
        head_new = Node(0)
        idxToNewNode = {}
        node_new = head_new
        idxToNewNode[0] = head_new
        for i in range(1, n):
            node_new.next = Node(0)
            node_new = node_new.next
            idxToNewNode[i] = node_new

        node = head
        node_new = head_new
        for i in range(n):
            node_new.val = node.val
            if node.random == None:
                node_new.random = None
            else:
                node_new.random = idxToNewNode[nodeToIdx[node.random]]
            
            node_new = node_new.next
            node = node.next
            
        return head_new