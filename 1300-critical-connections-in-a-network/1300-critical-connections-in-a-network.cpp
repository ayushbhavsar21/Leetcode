class Solution {
public:
    int timer = 1;
    void dfs(int node,int parent,vector<int>& tin,vector<int>& low,vector<int>& vis,vector<vector<int>>& ans,vector<vector<int>>& adj){
        vis[node] = 1;
        tin[node] = timer;
        low[node] = timer;
        timer++;

        for(auto it:adj[node]){
            if (it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,tin,low,vis,ans,adj);
                low[node] = min(low[it] , low[node]);

                if(tin[node] < low[it])
                    ans.push_back({it,node});
            }
            else
                low[node] = min(low[it] , low[node]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& c) {
        vector<vector<int>> adj(n);

        for(auto it:c){
            int u = it[0] , v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> tin(n,-1) , low(n,-1), vis(n,0);
        vector<vector<int>> ans;

        dfs(0,-1,tin,low,vis,ans,adj);

        return ans;

        
    }
};