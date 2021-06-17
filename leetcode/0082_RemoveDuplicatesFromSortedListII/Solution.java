/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        int negInf = -101;

        ListNode n = new ListNode(negInf);
        n.next = head;
        
        ListNode p1 = n;
        ListNode p2 = head;
        int val = negInf;
        while(true){
            if(p2 == null){
                break;
            }
            
            if(p2.next == null){
                break;
            }
            
            if(p2.next.val == p2.val){
                while(p2.next.val == p2.val){
                    p2.next = p2.next.next;
                    if(p2.next == null){
                        break;
                    }
                }
                p1.next = p2.next;
                p2 = p2.next;
            }
            else{
                p1 = p2;
                p2 = p2.next;
            }
        }
        
        return n.next;
    }
}