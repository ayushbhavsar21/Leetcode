struct Node {
    Node* list[26] = {nullptr}; 
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

void search(Node* root, const string& s, int start, vector<string>& ans, string t) {
    if (start == s.length()) {
        ans.push_back(t.substr(0, t.length() - 1)); 
        return;
    }

    Node* node = root;
    string word;
    for (int i = start; i < s.length(); i++) {
        char ch = s[i];
        if (node->list[ch - 'a'] == nullptr) {
            return;
        }
        node = node->list[ch - 'a'];
        word += ch;
        if (node->end) { 
            search(root, s, i + 1, ans, t + word + " ");
        }
    }
}

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Node* root = new Node();
        for (const string& word : wordDict) {
            insert(root, word);
        }
        vector<string> ans;
        search(root, s, 0, ans, "");
        return ans;
    }
};
