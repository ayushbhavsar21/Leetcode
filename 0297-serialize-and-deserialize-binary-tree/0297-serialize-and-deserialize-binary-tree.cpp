class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";

        string ans;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node) {
                ans += to_string(node->val) + ",";
                q.push(node->left);
                q.push(node->right);
            } else {
                ans += "null,";
            }
        }

        // Remove trailing comma
        if (!ans.empty()) ans.pop_back();

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "null") return nullptr;

        vector<string> nodes;
        stringstream ss(data);
        string token;

        while (getline(ss, token, ',')) {
            nodes.push_back(token);
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* current = q.front();
            q.pop();

            // Left child
            if (nodes[i] != "null") {
                TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
                current->left = leftNode;
                q.push(leftNode);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "null") {
                TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
                current->right = rightNode;
                q.push(rightNode);
            }
            i++;
        }

        return root;
    }
};
