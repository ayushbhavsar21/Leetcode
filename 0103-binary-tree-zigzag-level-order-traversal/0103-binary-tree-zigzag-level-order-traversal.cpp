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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool ok=true;

        while(!q.empty()){
            int n=q.size();
            vector<int> v(n);
            for(int i=0;i<n;i++){
                TreeNode* c=q.front();
                q.pop();
                if(c->left)
                    q.push(c->left);
                if(c->right)
                    q.push(c->right);
                int index;
                if(ok){
                    index = i;
                }
                else{
                    index = n - 1 -i;
                }
                v[index] = c->val;
            }
            ok=!ok;
            ans.push_back(v);
            
        }
        return ans;
    }
};