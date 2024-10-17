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
    ListNode* mergeKLists(vector<ListNode*>& v) {
        int n = v.size();
        ListNode* head = new ListNode(0);
        ListNode* ptr = head;
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0;i<n;i++){
            ListNode* p = v[i];
            while(v[i]){
                pq.push(v[i]->val);
                v[i] = v[i]->next;
            }
        }
        while(!pq.empty()){
            ListNode* t = new ListNode(pq.top());
            pq.pop();
            ptr->next = t;
            ptr = ptr->next;
        }

        return head->next;
    }
};