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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* next = head->next;
        ListNode* c = head;
        ListNode* prev = nullptr;

        while(c && c->next){
            ListNode* newnext = c->next->next;
            ListNode* s = c->next;

            s->next = c;
            c->next = newnext;

            if(prev)
                prev->next = s;

            prev = c;
            c = newnext;
        }
        return next;

        
    }
};