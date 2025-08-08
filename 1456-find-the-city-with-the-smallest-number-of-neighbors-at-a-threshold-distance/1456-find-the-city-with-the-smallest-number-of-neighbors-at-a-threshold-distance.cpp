class Solution {
public:
    void solve(vector<vector<int>>& adj){
        int n = adj.size();
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][k] < 1e9 && adj[k][j] < 1e9) {
                        adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        const int INF = 1e9;
        vector<vector<int>> adj (n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) adj[i][i] = 0;

        for(auto &it : edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u][v] = w;
            adj[v][u] = w;
        }

        solve(adj);

        int c1 = INT_MAX;
        int idx = -1;
        for(int i=0;i<n;i++){
            int c = 0;
            for(int j=0;j<n;j++){
                if(adj[i][j] <= t) c++;
            }
            if(c < c1 ) {
                c1 = c;
                idx = i;
            }
            else if(c == c1 && i > idx){
                idx = i;
            }
        }
        return idx;
    }
};
