
class Solution {
public:
    // void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int
    // x, int y) {
    //     int dx[4] = {-1, 1, 0, 0};
    //     int dy[4] = {0, 0, -1, 1};
    //     int n = board.size();
    //     int m = board[0].size();
    //     visited[x][y] = 1;
    //     for (int i = 0; i < 4; i++) {
    //         int nx = x + dx[i];
    //         int ny = y + dy[i];
    //         if (nx >= 0 && nx < n && ny >= 0 && ny < m  ) {
    //             if(board[nx][ny] == 'O' && visited[nx][ny]==0)
    //                 dfs(board, visited, nx, ny);
    //         }
    //     }
    // }

    void dfs(vector<vector<char>>& board, vector<vector<int>>& visited, int x,
             int y) {
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};
        int n = board.size();
        int m = board[0].size();
        visited[x][y] = 1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                if (board[nx][ny] == 'O' && visited[nx][ny] == 0) {
                    dfs(board, visited, nx, ny);
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        if (m == 0)
            return;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && visited[0][i] == 0) {
                dfs(board, visited, 0, i);
            }
            if (board[n - 1][i] == 'O' && visited[n - 1][i] == 0) {
                dfs(board, visited, n - 1, i);
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(board, visited, i, 0);
            }
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) {
                dfs(board, visited, i, m - 1);
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }

}
;