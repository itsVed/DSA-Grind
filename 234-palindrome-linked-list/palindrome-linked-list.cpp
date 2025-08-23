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
    bool isPalindrome(ListNode* head) {
        ListNode* temp = head;
        vector<int> vals;

        while(temp != NULL){
            vals.push_back(temp->val);
            temp = temp->next;
        }

        int n = vals.size();
        
        for(int i = 0; i < n/2; i++){
            if(vals[i] != vals[n-1-i]) return false;
        }

        return true;
    }
};