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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* last = head, *curr = head->next;

        while(curr){
            if(curr->val >= last->val){
                last = curr;
            }
            else{
                ListNode* prev = dummy;
                while(prev->next->val < curr->val)
                    prev = prev->next;

                last->next = curr->next;
                curr->next = prev->next; 
                prev->next = curr;
            }
            curr = last->next;
        }
        return dummy->next;
    }
};