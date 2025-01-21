class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);
        vector<int> ans;
        queue<int> q;
        unordered_set<int> visited;

        for(auto& edge : prerequisites){
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                visited.insert(i);
            }
        }

        while(!q.empty()){
            int course = q.front();
            q.pop();
            ans.push_back(course);
            for(int neighbor : adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0 ){
                    q.push(neighbor);
                    visited.insert(neighbor);
                }
            }
        }

        if(ans.size() == n)
            return ans;
        
        return {};
    }
};
