struct Node{
    Node* list[26];
    bool end = 0;
};
void insert(Node* root , string& s){
    Node* node = root;
    for(auto it:s){
        if(node->list[it - 'a'] == nullptr)
            node->list[it - 'a'] = new Node();
        node = node->list[it - 'a'];
    }
    node->end = 1;
}
class Solution {
public:
    bool search(Node* root,int i,string& s,vector<int>& dp ){
        if(i == s.length() )
            return 1;

        if(dp[i] != -1)
            return dp[i];

        Node* node = root;
        for(int j = i;j<s.length();j++){
            char c = s[j];
            if(node->list[c - 'a'] == nullptr)
                return dp[i] = 0;

            node = node->list[c - 'a'];
            if(node->end){
                if(search(root , j+1 ,s , dp))
                    return dp[i] = 1;
            }
        }
        return dp[i] = 0;
    }
    bool wordBreak(string s, vector<string>& v) {
        Node* root = new Node();
        for(auto it:v){
            insert(root , it);
        }
        vector<int> dp (s.length() , -1);
        return search(root , 0 , s ,dp);
    }
};