class Solution {
public:
    bool solve(TreeNode* root, long long mini, long long maxi) {
        if (!root) {
            return true;
        }
        
        if (root->val <= mini || root->val >= maxi) {
            return false;
        }
        bool l = solve(root->left, mini, root->val);
        bool r = solve(root->right, root->val, maxi);
        
        return l && r;
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
