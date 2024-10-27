class Solution {
public:
    int dfs(int i,vector<vector<int>> &adj,vector<int> &ans){
        int s = 1;
        for(auto it:adj[i]){
            s += dfs(it,adj,ans);
        }
        ans[i] = s;
        return s;
    }
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        vector<int> p2  = p;
        int n = p.size();
        
        for(int i=1;i<n;i++){
            int y = p[i];

            while(y != -1 && s[y] != s[i]){
                y = p[y];
            }
            if(y != -1){
                p2[i] = y;
            }
        }

        vector<vector<int>> adj (n);
        for(int i=1;i<n;i++){
            adj[p2[i]].push_back(i);
        }
        vector<int> ans(n,0);
        dfs(0,adj,ans);
        return ans;

    }
};