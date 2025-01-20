class Solution {
public:
    int n,m; 
    void bfs(int i,int j,vector<vector<char>>& grid){
        queue<int> q;
        q.push( (m*i + j));
        grid[i][j] = '0';
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        while(!q.empty()){
            int x = q.front()/m;
            int y = q.front()%m;
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny] == '1'){
                    q.push((m*nx + ny));
                    grid[nx][ny] = '0';
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();

         int ans = 0;

         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '1'){
                    bfs(i,j,grid);
                    ans++;
                }
            }
         }
         return ans;
    }
};