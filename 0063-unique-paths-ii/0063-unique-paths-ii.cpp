class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();

        if(v[n-1][m-1] == 1 || v[0][0] == 1)
            return 0;
        vector<vector<int>> dp (n + 1 , vector<int>(m +1 , 0));
        dp[0][0] = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j==0) continue;

                if(i-1 >= 0 && v[i][j] == 0 ){
                    dp[i][j] += dp[i-1][j] ;
                }
                if(j-1 >= 0 && v[i][j] == 0 ){
                    dp[i][j] += dp[i][j-1] ;
                }             
            }
        }
        return dp[n-1][m-1];
    }
};