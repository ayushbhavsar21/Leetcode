class BSTIterator {
public:
    stack<TreeNode*> st;
    void left(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        
        left(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        int val = node->val;

        
        if (node->right) {
            left(node->right);
        }
        
        return val;
    }
    
    
    bool hasNext() {
        return !st.empty();
    }    
};
