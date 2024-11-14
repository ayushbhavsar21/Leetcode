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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* ptr = new ListNode(0);
        ptr->next = head;
        ListNode* pre = ptr;
        ListNode* c = head;

        while(c){
            bool ok = 0;
            while(c->next &&c->val == c->next->val){
                ok =1;
                c = c->next;
            }
            if(ok){
                pre->next = c->next;
            }
            else
                pre= pre->next;
            c = c->next;
        }
        
        return ptr->next;
    }
};