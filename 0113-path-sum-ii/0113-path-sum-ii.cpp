class Solution {
public:
    void solve(TreeNode* root, int t, vector<int>& v, vector<vector<int>>& ans) {
        if (!root) {
            return; 
        }
        v.push_back(root->val);
        
        
        if (!root->left && !root->right && t == root->val) {
            ans.push_back(v);
        } else {
            
            solve(root->left, t - root->val, v, ans);
            solve(root->right, t - root->val, v, ans);
        }
        
        v.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        solve(root, t, v, ans);
        return ans;
    }
};
