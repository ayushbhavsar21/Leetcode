class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
       int n = grid.size();
       int m = grid[0].size();
       vector<vector<int>> dp(n ,vector<int>(m , 0));
       dp[0][0] = grid[0][0];

       for(int i=0;i<n;i++){
        for(int j =0;j<m;j++){
            if(i==0 && j==0) continue;

            int r1,r2,r3,r4;
            r1=r2=r3=r4 = INT_MAX;

            if(i>0)
                r1 = dp[i-1][j];
            if(j>0)
                r3 = dp[i][j-1];

            dp[i][j] = min({r1 , r3  }) + grid[i][j];
        }
       }

        // for(auto it:dp){
        //     for(auto it2:it)
        //         cout<<it2<<" ";
        //     cout<<endl;
        // }

        return dp[n-1][m-1];
    }
};