// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Given the head of a linked list, remove the n-th node from the end of the list and return its head. 
class Solution 
{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode dummy(0, head); // dummy node points to head
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;
        
        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++)
            fast = fast->next;
        
        // Move both until fast reaches the end
        while (fast != nullptr) 
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        // slow->next is the node to remove
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        delete nodeToDelete; // free memory
        
        return dummy.next;
    }
};
