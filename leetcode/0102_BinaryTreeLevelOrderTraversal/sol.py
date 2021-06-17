# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        
        queue = Queue()
        queue.append([root, 0])
        ret = []        
        while not queue.isEmpty():
            node, level = queue.pop()
            if level + 1 > len(ret):
                ret.append([])
            
            ret[-1].append(node.val)
            if node.left != None:
                queue.append([node.left, level+1])
            if node.right != None:
                queue.append([node.right, level+1])
        
        return ret
  
class Node():
    def __init__(self, val):
        self.val = val
        self.next = None

class Queue():
    def __init__(self):
        self.head = Node(None)
        self.tail = None
    
    def append(self, val):
        if self.head.next == None:
            self.head.next = Node(val)
            self.tail = self.head.next
        else:
            self.tail.next = Node(val)
            self.tail = self.tail.next
            
    def pop(self):
        n = self.head.next
        self.head.next = n.next
        return n.val

    def isEmpty(self):
        if self.head.next == None:
            return True
        else:
            return False