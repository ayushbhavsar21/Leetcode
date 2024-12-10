/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root){
        if(!root)
            return;

        solve(root->right);
        solve(root->left);

        TreeNode* ptr = root->right;
        root->right = root->left;
        root->left = nullptr;


        while(root->right){
            root = root->right;
        }
        root->right = ptr;
    }



    void flatten(TreeNode* root) {
        TreeNode* node = root;
        solve(node);
    }
};