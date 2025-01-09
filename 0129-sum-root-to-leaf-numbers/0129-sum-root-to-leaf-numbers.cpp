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
    int ans = 0;
    int dfs(int num,TreeNode* node){
        if(!node->left && !node->right){
            num = num*10 + node->val;
            return num;
        }

        num = num*10 + node->val;

        if(node->left){
            ans += dfs(num , node->left);
        }
        if(node->right){
            ans += dfs(num , node->right);
        }
        return 0;

    }
    int sumNumbers(TreeNode* root) {
        if(!root->left && !root->right){            
            return root->val;
        }
        dfs(0 , root);
        return ans;
    }
};