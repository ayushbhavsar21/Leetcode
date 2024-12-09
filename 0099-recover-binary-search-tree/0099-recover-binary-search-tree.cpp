class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = new TreeNode(INT_MIN);

    void inorder(TreeNode* root) {
        if (!root) return;

       
        inorder(root->left);

        if (!first && prev->val > root->val) {
            first = prev; 
        }
        if (first && prev->val >= root->val) {
            second = root;
        }


        prev = root;

 
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        if (first && second) {
            swap(first->val, second->val);
        }
    }
};
