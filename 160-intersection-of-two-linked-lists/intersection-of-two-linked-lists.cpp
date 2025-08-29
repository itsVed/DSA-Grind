/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int m = 0;
        int n = 0;

        ListNode *l1 = headA;

        while(l1){
            m++;
            l1 = l1->next;
        }

        ListNode *l2 = headB;

        while(l2){
            n++;
            l2 = l2->next;
        }

        l1 = headA;
        l2 = headB;

        if(m > n){
            while(m != n){
                --m;
                l1 = l1->next;
            }
        }
        else{
            while(m != n){
                --n;
                l2 = l2->next;
            }
        }

        while(l1 and l2 and l1 != l2){
            l1 = l1->next;
            l2 = l2->next;
        }

        return l1;
    }
};