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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry =0;

        while(l1 || l2){
            int x= (l1)? l1->val:0;
            int y=(l2)? l2->val:0;
            int sum =x+y+carry;
            carry=sum/10;
            curr->next = new ListNode(sum%10);
            curr=curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry > 0) {
            curr -> next = new ListNode(carry); 
        }
        return dummy->next;
    }
};
************************************************************************************************************************************************************************************************************************
//using Recursion
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
    ListNode* addList(ListNode* l1, ListNode* l2, int carry){
        if(!l1 && !l2){
            if(carry>0){
                return new ListNode(carry);
            }
            return nullptr;
        }
            int x= (l1)? l1->val:0;
            int y=(l2)? l2->val:0;
            int sum =x+y+carry;
            carry=sum/10;
            ListNode* result = new ListNode(sum%10);
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;

            result->next = addList(l1,l2,carry);
            return result;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return addList(l1,l2,0);
    }
};
