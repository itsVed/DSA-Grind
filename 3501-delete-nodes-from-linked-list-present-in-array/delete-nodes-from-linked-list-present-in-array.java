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

    public ListNode modifiedList(int[] nums, ListNode head) {
        Set<Integer> st = new HashSet<>();  

        for(int n : nums){
            st.add(n);
        } 

        ListNode dummy = new ListNode(0);
        dummy.next = head;
        
        ListNode prev = dummy;
        ListNode temp = head;

        while(temp != null){

            if(st.contains(temp.val)){
                prev.next = temp.next;
            }
            else{
                prev = temp;
            }

            temp = temp.next;
        }
        
        return dummy.next;
    }
}