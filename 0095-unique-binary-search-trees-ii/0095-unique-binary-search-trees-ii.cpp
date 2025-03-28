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
    map<pair<int,int>,vector<TreeNode*>>dp;
    vector<TreeNode*> buildTree(int start, int end) {
        vector<TreeNode*> ans;

        if (start > end) {
            ans.push_back(NULL);
            return ans;
        }
        if(dp.find({start,end})!=dp.end()){
            // cout<<c++<<endl;
            return dp[{start,end}];
        }
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTree = buildTree(start, i - 1); 
            vector<TreeNode*> rightSubTree = buildTree(i + 1, end);
            // for(auto it:leftSubTree)    cout<<it<<" ";
            // cout<<endl; 
            // for(auto it:rightSubTree)    cout<<it<<" ";

            for (int j = 0; j < rightSubTree.size(); j++) {
                for (int k = 0; k < leftSubTree.size(); k++) {
                    TreeNode* root = new TreeNode(i);        
                    root->left = leftSubTree[k]; 
                    root->right = rightSubTree[j];
                    ans.push_back(root); 
                }
            }
        }

        return  dp[{start,end}]=ans;
    }

    vector<TreeNode*> generateTrees(int n) { 
        return buildTree(1, n); 
    }
};