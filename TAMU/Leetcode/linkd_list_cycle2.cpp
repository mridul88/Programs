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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast, *slow;
        fast = slow = head;
        while(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast==NULL)
                return NULL;  // No Cycle
            else
                fast = fast->next;

            if(slow == fast)
                break;   // Cycle detected
        }
        if(fast == NULL)
            return NULL;
        slow = head;
        while(slow!=fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
