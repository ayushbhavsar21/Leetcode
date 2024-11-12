class Solution {
public:

    bool solve(int x,int y,int index,vector<vector<char>>& board, string word,vector<vector<int>>& visited){
        if(index >= word.length())
            return true;
        
        int dx[4] = {-1,1,0,0};
        int dy[4] = {0,0,-1,1};
        int n = board.size();
        int m = board[0].size();

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m ){
                if(board[nx][ny] == word[index] && visited[nx][ny] == 0){
                    visited[nx][ny] = 1;
                    bool ok = solve(nx ,ny ,index +1 ,board ,word ,visited);
                    // cout<<ok<<endl;
                    visited[nx][ny] = 0;
                    if(ok)
                        return true;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> visited (n , vector<int> (m , 0) ) ; 

        char first  = word[0];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j] == first){
                    visited[i][j] = 1;
                    bool ok = solve(i , j , 1 , board , word , visited);
                    visited[i][j] = 0;
                    if(ok )
                        return true ;
                }
            }
        }
        return false;
    }
};