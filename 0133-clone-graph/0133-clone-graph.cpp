/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)
            return nullptr;
        unordered_map<Node*,Node*> mp;
        mp[node] = new Node(node->val);

        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* ptr1 = q.front();
            q.pop();
            for(auto it:ptr1->neighbors){
                if(!mp.count(it)){
                    mp[it] = new Node(it->val);
                    q.push(it);
                }
                mp[ptr1]->neighbors.push_back(mp[it]);
            }
            
        }
        return mp[node];
    }
};