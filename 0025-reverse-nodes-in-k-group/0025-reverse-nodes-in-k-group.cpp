class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = nullptr; 
        ListNode* current = head;
        while (k > 0 && current != nullptr) {
            ListNode* nextNode = current->next;  
            current->next = prev;                
            prev = current;                      
            current = nextNode;                  
            k--;
        }
        return prev;  
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        
        ListNode* ptr = head;
        int count = 0;
        while (ptr != nullptr && count < k) {
            ptr = ptr->next;
            count++;
        }
        
        
        if (count == k) {
            
            ListNode* newHead = reverse(head, k);
            
            
            head->next = reverseKGroup(ptr, k);
            
            
            return newHead;
        }

        
        return head;
    }
};
