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
        struct ListNode* slow=head;
        struct ListNode* fast=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast)
            slow=slow->next;
        ListNode* prev=NULL;
        while(slow){
            struct ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        struct ListNode* a=head;
        struct ListNode* b=prev;
        while(b){
            if(a->val==b->val){
                a=a->next;
                b=b->next;
            }
            else
                return false;
        }
        return true;
    }
};
