*******************************************************************Approach1******************************************************************************************
                                                                   //Recursion
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        if(head->val == val) return removeElements(head->next, val);
        head->next = removeElements(head->next, val);
        return head;
    }
};

********************************************************************Approach2***************************************************************************************                                                                   //Iterative
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        // Create a dummy node to serve as the new head.
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* current = dummy;
        
        while (current->next) {
            if (current->next->val == val) {
                // Found a node with the value to be removed, skip it.
                ListNode* toRemove = current->next;
                current->next = current->next->next;
                delete toRemove;
            } else {
                // Move to the next node.
                current = current->next;
            }
        }
        
        // The modified list starts from dummy->next.
        head = dummy->next;
        delete dummy; // Delete the dummy node.
        
        return head;
    }
};

