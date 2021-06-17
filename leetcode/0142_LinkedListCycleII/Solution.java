/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if(head == null){
            return null;
        }
        
        ListNode p1 = head;
        ListNode p2 = head;
        
        while(true){
            p1 = this.getNext(p1, 1);
            p2 = this.getNext(p2, 2);
            if(p1 == null || p2 == null){
                return null;
            }
            
            if(p1 == p2){
                break;
            }
        }
        
        p1 = head;
        while(true){
            // since it is possible that ret = head;
            // need to consider what if ret = head!
            if(p1 == p2){
                break;
            }
            p1 = this.getNext(p1, 1);
            p2 = this.getNext(p2, 1);
        }
        
        return p1;
    }
    
    private ListNode getNext(ListNode p, int moves){
        for(int i=0; i<moves; i++){
            if(p.next == null){
                return null;
            }
            p = p.next;
        }
        
        return p;
    }
}