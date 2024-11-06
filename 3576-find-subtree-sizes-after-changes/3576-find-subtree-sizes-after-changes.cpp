class Solution {
public:
    void change(int i, vector<int>& closean, vector<int>& newp, vector<vector<int>>& adj, string& s) {
        int c = s[i] - 'a';
        
        
        if(closean[c] != -1) {
            newp[i] = closean[c];
        }
        
        int oldan = closean[c];
        closean[c] = i;
        
        for(auto it : adj[i]) {
            change(it, closean, newp, adj, s);
        }
        
        closean[c] = oldan;
    }
    
    int dfs(int i, vector<vector<int>>& newadj, vector<int>& ans) {
        int size = 1;
        
        for(auto it : newadj[i]) {
            size += dfs(it, newadj, ans);
        }
        return ans[i] = size;
    }
    
    vector<int> findSubtreeSizes(vector<int>& p, string s) {
        int n = p.size();
        vector<int> closean(26, -1);
        
        vector<int> newp = p;
        vector<vector<int>> adj(n);
        vector<vector<int>> newadj(n);
        
        
        for(int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }
        
        change(0, closean, newp, adj, s);
        
        
        for(int i = 1; i < n; i++) {
            newadj[newp[i]].push_back(i);
        }
        
        vector<int> ans(n, 0);
        dfs(0, newadj, ans);
        
        return ans;
    }
};