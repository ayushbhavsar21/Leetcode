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
    ListNode* mergesort(ListNode* head) {
        if (!head || !head->next) {
            return head; 
        }

       
        ListNode* fast = head->next;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;

        
        ListNode* l = mergesort(head);
        ListNode* r = mergesort(mid);

        ListNode* dummy = new ListNode(0);
        ListNode* p1 = dummy;

        while (l && r) {
            if (l->val < r->val) {
                p1->next = l;
                l = l->next;
            } else {
                p1->next = r;
                r = r->next;
            }
            p1 = p1->next;
        }

        
        if (l) p1->next = l;
        if (r) p1->next = r;

        return dummy->next;
    
    }

    ListNode* sortList(ListNode* head) {
        return mergesort(head);
    }
};
