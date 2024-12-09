class Solution {
public:
    TreeNode* solve(int preStart, int inStart, int inEnd, vector<int>& pre, vector<int>& in1) {
        if (preStart >= pre.size() || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(pre[preStart]);

        int inIndex = inStart;
        while (inIndex <= inEnd && in1[inIndex] != pre[preStart]) {
            inIndex++;
        }

        
        node->left = solve(preStart + 1, inStart, inIndex - 1, pre, in1);

        node->right = solve(preStart + (inIndex - inStart) + 1, inIndex + 1, inEnd, pre, in1);

        return node;
    }

    TreeNode* buildTree(vector<int>& pre, vector<int>& in1) {
        return solve(0, 0, in1.size() - 1, pre, in1);
    }
};
