struct Node {
    Node* list[26] = {nullptr};
    bool end = false;           
};

class WordDictionary {
private:
    Node* root;

    bool dfs(Node* node, string& s, int i) {
        if (i == s.length()) {
            return node->end; 
        }

        if (s[i] == '.') {
            for (int j = 0; j < 26; j++) { 
                if (node->list[j] && dfs(node->list[j], s, i + 1)) {
                    return true;
                }
            }
        } else {
            if (node->list[s[i] - 'a'] == nullptr) {
                return false; 
            }
            return dfs(node->list[s[i] - 'a'], s, i + 1);
        }

        return false;
    }

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string s) {
        Node* node = root;
        for (char c : s) {
            if (node->list[c - 'a'] == nullptr) {
                node->list[c - 'a'] = new Node();
            }
            node = node->list[c - 'a'];
        }
        node->end = true;
    }

    bool search(string s) {
        return dfs(root, s, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
