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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)   
            return nullptr;
        TreeNode* ans = root;
        int maxi = max(p->val,q->val);
        int mini = min(p->val,q->val);
        while(ans){
            if(ans->val > maxi)
                ans = ans->left;
            else if(ans->val < mini)
                ans = ans->right;
            else 
                return ans;
        }
        return root;
    }
};