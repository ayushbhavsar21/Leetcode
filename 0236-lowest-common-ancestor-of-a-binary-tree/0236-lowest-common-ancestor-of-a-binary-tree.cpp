/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || p== root || q == root)
            return root;
        
        TreeNode* right = solve(root->right ,  p ,q);
        TreeNode* left = solve(root->left ,  p ,q);

        if(!right)
            return left;
        else if(!left)
            return right;
        else 
            return root;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};