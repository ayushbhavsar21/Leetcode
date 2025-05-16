class Solution {
public:
    static bool cmp(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first;
    }

    void inorder(TreeNode* root, int x, int y, map<int, vector<pair<int, int>>>& mp) {
        if (!root)
            return;
        inorder(root->left, x + 1, y - 1, mp);

        mp[y].push_back({x, root->val});

        inorder(root->right, x + 1, y + 1, mp);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans; 
        map<int, vector<pair<int, int>>> mp;
        inorder(root, 0, 0, mp);

        for (auto [y, v] : mp) {
            sort(v.begin(), v.end(), cmp);
            vector<int> temp;
            for (auto it : v) {
                temp.push_back(it.second);
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};
