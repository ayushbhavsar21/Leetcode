class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& v) {
        if(v.size() == 0)
            return true;

        vector<int> indegree(n, 0);
        vector<vector<int>> adj(n);

        
        for(auto& i : v){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0;
        while(!q.empty()){
            int course = q.front();
            q.pop();
            count++;
            for(int neighbor : adj[course]){
                indegree[neighbor]--;
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }
        }

        return count == n;
    }
};
