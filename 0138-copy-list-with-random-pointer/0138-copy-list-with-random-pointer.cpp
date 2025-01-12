/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        unordered_map<Node*,Node*> mp;
        mp[head] = new Node(head->val);
        queue<Node*>q;
        q.push(head);
        while(!q.empty()){
            Node* p = q.front();
            q.pop();
            if(p->next){
                if(!mp.count(p->next)){
                    mp[p->next] = new Node(p->next->val);
                    q.push(p->next);
                }
                mp[p]->next = mp[p->next];
            }
            if(p->random){
                if(!mp.count(p->random)){
                    mp[p->random] = new Node(p->random->val);
                    q.push(p->random);
                }
                mp[p]->random = mp[p->random];
            }
        }
        return mp[head];
    }
};