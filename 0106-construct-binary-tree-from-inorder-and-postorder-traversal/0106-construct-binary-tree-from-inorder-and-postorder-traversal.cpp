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
TreeNode* solve(int postend, int inStart, int inEnd, vector<int>& post, vector<int>& in1) {
        if (postend >= post.size() || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(post[postend]);

        int inIndex = inStart;
        while (inIndex <= inEnd && in1[inIndex] != post[postend]) {
            inIndex++;
        }

        
        node->left = solve(postend - (inEnd - inIndex) - 1, inStart, inIndex - 1, post, in1);

        node->right = solve(postend - 1, inIndex + 1, inEnd, post, in1);

        return node;
    }
    TreeNode* buildTree(vector<int>& in1, vector<int>& post) {
        int n = post.size();
        TreeNode* root = solve(n-1 , 0 , n-1 , post , in1); 
        return root;
    }
};