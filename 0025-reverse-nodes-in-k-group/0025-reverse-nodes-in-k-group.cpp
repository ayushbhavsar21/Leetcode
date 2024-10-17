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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ptr = head;
        vector<int> v;
        while(ptr){
            v.push_back(ptr->val);
            ptr = ptr->next;
        }
        for(int i=0;i+k <= v.size() ;i+=k){
            reverse(v.begin()+i , v.begin()+i  + k );
        }
        ptr = head;
        int i=0;
        while(ptr){
            ptr->val = v[i];
            i++;
            ptr = ptr->next;
        }
        return head;
    }
}
;