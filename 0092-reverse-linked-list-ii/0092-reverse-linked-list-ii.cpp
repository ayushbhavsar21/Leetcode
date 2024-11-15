class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if (!head || l == r) return head;

        ListNode* dummy = new ListNode(0); 
        dummy->next = head;
        ListNode* prev = dummy;

        
        for (int i = 1; i < l; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next; 
        ListNode* next = nullptr;
        ListNode* tail = curr; 
        for (int i = 0; i < r - l + 1; i++) {
            next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }

        
        tail->next = curr;

        return dummy->next;
    }
};
