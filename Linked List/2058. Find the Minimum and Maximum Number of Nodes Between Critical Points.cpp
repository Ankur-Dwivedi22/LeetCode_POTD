// Approach : Traversal and Pointers
// TC : O(N)
// SC : O(1)

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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        int d = 0;
        int first = -1, last = -1, adj = -1;
        int mn = INT_MAX;
        while(temp != NULL){
            ListNode* ahead = NULL;
            d++;
            if(temp->next != NULL){
                ahead = temp->next;
            }

            if(prev != NULL && ahead != NULL){
                if((temp->val > prev->val && temp->val > ahead->val) || (temp->val < prev->val && temp->val < ahead->val)){
                    if(adj != -1){
                        mn = min(mn, d - adj);
                    }
                    adj = d;
                    if(first == -1) first = d;
                    last = d;
                }
            }

            prev = temp;
            temp = temp->next;
        }

        if(first == -1 || last == -1 || mn == INT_MAX){
            return {-1, -1};
        }
        int mx = last - first;
        return {mn, mx};
    }
};
