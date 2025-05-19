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
    TreeNode* solve(TreeNode* node){
        if(!node->left) return node->right;
        if(!node->right) return node->left;

        TreeNode* r = node->right;
        TreeNode* l = node->left;
        while(l->right){
            l = l->right;
        }
        l->right = r;
        return node->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val == key) 
            return solve(root);

        TreeNode* ptr = root;
        while(ptr){
            if(ptr->val > key){
                if(ptr->left && ptr->left->val == key){
                    ptr->left = solve(ptr->left);
                    return root;
                }
                else
                    ptr = ptr->left;
            }
            else{
                if(ptr->right && ptr->right->val == key){
                    ptr->right = solve(ptr->right);
                    return root;
                }
                else
                    ptr = ptr->right;
            }
        }
        return root;
    }
};