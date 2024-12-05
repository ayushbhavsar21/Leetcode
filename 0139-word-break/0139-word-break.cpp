struct Node {
    Node* list[26]; 
    bool end = false;           
};

void insert(Node* root, const string& s) {
    Node* node = root;
    for (char c : s) {
        if (node->list[c - 'a'] == nullptr) {
            node->list[c - 'a'] = new Node();
        }
        node = node->list[c - 'a'];
    }
    node->end = true;
}

bool search(Node* root, const string& s, int start, vector<int>& dp) {
    if (start == s.length()) 
        return true;
    if (dp[start] != -1) 
        return dp[start];

    Node* node = root;
    for (int i = start; i < s.length(); i++) {
        char c = s[i];

        if (node->list[c - 'a'] == nullptr) 
            return dp[start] = false; 
        node = node->list[c - 'a'];
        if (node->end) { 
            if (search(root, s, i + 1, dp)) 
                return dp[start] = true;
        }
    }
    return dp[start] = false;
}

class Solution {
public:
    bool wordBreak(string s, vector<string>& w) {
        Node* root = new Node();
        for ( string& word : w) {
            insert(root, word);
        }
        vector<int> dp(s.length(), -1);
        return search(root, s, 0, dp);
    }
};
