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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        int c = 0;
        bool ok = 0;
        ListNode* prev = new ListNode(0);
        while(l1 && l2){
            int s = l1->val + l2->val + c;
            c = s/10;
            s = s%10;
            l1->val = s;
            l2->val = s;
            prev = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            ok =1;
            int s = l1->val + c;
            c = s/10;
            s = s%10;
            l1->val = s;
            prev = l1;
            l1 = l1->next;
        }
        while(l2){
            int s = l2->val + c;
            c = s/10;
            s = s%10;
            l2->val = s;
            prev = l2;
            l2 = l2->next;
        }
        if(c!=0){
            ListNode* t = new ListNode(c);
            prev->next = t;
        }
        if(ok)
            return ptr1;
        return ptr2;
    }
};