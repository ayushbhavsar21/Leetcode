class Solution {
public:
    
    int dfs(TreeNode* root, unordered_map<TreeNode*, int>& mp) {
        if (!root) return 0; 
        
        int l = dfs(root->left, mp);  
        int r = dfs(root->right, mp); 
        
        mp[root] = l + r + 1; 
        return mp[root];
    }

    
    int kthSmallest(TreeNode* root, int k) {
        unordered_map<TreeNode*, int> mp;
        dfs(root, mp); 
        
        TreeNode* curr = root;
        while (curr) {
            int leftSize = (curr->left ? mp[curr->left] : 0);
            
            if (leftSize + 1 == k) {
                return curr->val; 
            } else if (leftSize + 1 < k) {
                k -= (leftSize + 1); 
                curr = curr->right;
            } else {
                curr = curr->left; 
            }
        }
        
        return -1;
    }
};