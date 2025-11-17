/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if(!head || !head->next)
        return NULL;
    struct ListNode* fast=head;
    struct ListNode* slow=head;
    while(n--){
        fast=fast->next;
    }
    if(!fast){
        struct ListNode* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    while(fast->next){
        fast=fast->next;
        slow=slow->next;
    }
    struct ListNode* curr=slow->next;
    slow->next=slow->next->next;
    free(curr);
    return head;
}
