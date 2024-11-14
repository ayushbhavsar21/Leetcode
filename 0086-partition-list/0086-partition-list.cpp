class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* p1 = new ListNode(0);  
        ListNode* p2 = new ListNode(0); 
        ListNode* less = p1;              
        ListNode* more = p2;        

        ListNode* c = head;
        
        while (c) {
            if (c->val < x) {
                less->next = c;
                less = less->next;
            } else {
                more->next = c;
                more = more->next;
            }
            c = c->next;
        }

        
        more->next = nullptr; 
        less->next = p2->next; 

        ListNode* ans = p1->next; 
        delete p1;
        delete p2;

        return ans;
    }
};
