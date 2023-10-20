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
    bool pali(ListNode * &head, ListNode * head1){
        if(head1==NULL){
            return true;
        }
        bool x=pali(head,head1->next);
        if(head==NULL){return false;}
        if (head->val!=head1->val){
            head->next=NULL;
            return false;
        }
        head=head->next;
        return x;
    }


    bool isPalindrome(ListNode* head) {
        return pali(head,head);    
    }
};