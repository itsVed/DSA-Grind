/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode *kthnodefind(ListNode *head, int k){
        k -= 1;
        ListNode *temp = head;
        while(temp and k > 0){
            k--;
            temp = temp->next;
        }

        return temp;
    }

    ListNode *reverse(ListNode *head){
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while(curr){
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *nextnode;

        while(temp){

            ListNode *kthnode = kthnodefind(temp, k);

            if(kthnode == NULL){
                if(prev) prev->next = temp;
                break;
            }
            
            nextnode = kthnode->next;
                kthnode->next = NULL;

                reverse(temp);

                if(head == temp){
                    head = kthnode;
                }else{
                    prev->next = kthnode;
                }

                prev = temp;
                temp = nextnode;

        }

        return head;

    }
};