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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;

        if(n == 0) return NULL; 

        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;

        for (int i = 0; i < n; i++) {
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();

            temp->next = it.second;
            temp = it.second;

            if(it.second->next) pq.push({it.second->next->val, it.second->next});
        }

        return dummy->next;
    }
};