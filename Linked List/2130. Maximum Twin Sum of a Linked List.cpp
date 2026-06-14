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
class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = NULL;
        ListNode *temp = slow;
        while (temp != NULL)
        {
            ListNode *next = temp->next;
            temp->next = prev;
            prev = temp;
            temp = next;
        }
        ListNode *start = head;
        ListNode *back = prev;
        int maxSum = 0;
        while (back != NULL)
        {
            int sum = start->val + back->val;
            maxSum = max(maxSum, sum);
            start = start->next;
            back = back->next;
        }

        return maxSum;
    }
};