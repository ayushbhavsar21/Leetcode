class Solution {
public:
    int coinChange(vector<int>& v, int t) {
        int n = v.size();
        vector<vector<int>> dp(n,vector<int>(t+1,0));
        
        for (int i = 1; i <= t; i++) {
            if (i % v[0] == 0)
                dp[0][i] = i / v[0];
            else
                dp[0][i] = 1e9;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=t;j++){
                int r1 = dp[i-1][j];
                int r2 = INT_MAX;
                if(j >= v[i]){
                    r2 = 1 + dp[i][j - v[i]];
                    
                }
                dp[i][j] = min(r1,r2);
            }
        }

        return dp[n-1][t] >=1e9 ? -1 : dp[n-1][t];
    }
};