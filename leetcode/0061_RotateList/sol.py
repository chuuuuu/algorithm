# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def rotateRight(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        if head == None:
            return head
        
        if k == 0:
            return head
        
        n = head
        count = 1
        while n.next != None:
            n = n.next
            count += 1
        k = k % count
        if k == 0:
            return head

        n.next = head        
        n = head
        for i in range(count-k-1):
            n = n.next
        
        head = n.next
        n.next = None
        return head
        
        