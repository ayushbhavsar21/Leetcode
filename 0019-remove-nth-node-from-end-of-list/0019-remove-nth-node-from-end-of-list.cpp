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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        int s=0;
        ListNode* p1 = head;
        while(p1){
            p1 = p1->next;
            s++;
        } 
        // cout<<s<<" "<<s-n<<endl;
        if(s-n == 0){
            head = head->next;
            return head;
        }
        p1 = head ;
        for(int i=0;i< s - n - 1; i++){
            p1 = p1->next;
        }
        if(p1->next->next)
            p1->next = p1->next->next;
        else
            p1->next = nullptr;
       
            

        return head;

    }
};