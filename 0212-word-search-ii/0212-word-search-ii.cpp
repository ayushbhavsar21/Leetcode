struct Node {
    Node* list[26];
    string w = "";
    Node() {
        for (int i = 0; i < 26; ++i)
            list[i] = nullptr;
    }
};

void insert(Node* root, const string& s) {
    Node* node = root;
    for (char c : s) {
        if (node->list[c - 'a'] == nullptr) {
            node->list[c - 'a'] = new Node();
        }
        node = node->list[c - 'a'];
    }
    node->w = s; // Store the word at the end
}

void search(int i, int j, Node* node, vector<string>& ans, vector<vector<char>>& board) {
    char c = board[i][j];
    if (c == '#' || node->list[c - 'a'] == nullptr) {
        return; // Cell already visited or no matching Trie child
    }

    node = node->list[c - 'a'];
    if (!node->w.empty()) {
        ans.push_back(node->w); // Add word to result
        node->w = "";          // Mark word as found to avoid duplicates
    }

    board[i][j] = '#'; // Mark cell as visited
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto [di, dj] : directions) {
        int ni = i + di, nj = j + dj;
        if (ni >= 0 && ni < board.size() && nj >= 0 && nj < board[0].size()) {
            search(ni, nj, node, ans, board);
        }
    }
    board[i][j] = c; // Restore cell
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (const string& word : words) {
            insert(root, word);
        }

        vector<string> ans;
        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                search(i, j, root, ans, board);
            }
        }

        return ans;
    }
};

