/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head)
            return nullptr;
        ListNode* slow = head;
        unordered_set<ListNode*> st;
        

        while(slow){
            if(st.count(slow))
                return slow;
            st.insert(slow) ;
            slow = slow->next;            
        }
        return nullptr;
    }
};