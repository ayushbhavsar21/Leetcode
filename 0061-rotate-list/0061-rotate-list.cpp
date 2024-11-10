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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0) return head;
        
        int size = 1;
        ListNode* ptr = head;

        while(ptr->next){
            ptr = ptr->next;
            size ++;
        }
        k = k % size ;
        int k2 = size - k;
        cout<<k2<<endl;

        ptr->next = head;
        while(k2--){
            ptr = ptr->next;
        }
        ListNode* nhead = ptr->next;
        ptr->next = nullptr ;

        return nhead;

    }
};