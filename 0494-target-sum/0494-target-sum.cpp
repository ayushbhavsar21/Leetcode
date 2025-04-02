class Solution {
public:
    
    int findTargetSumWays(vector<int>& v, int t) {
        int n = v.size();
        int total = accumulate(v.begin(),v.end(),0);
        if ((total - t) < 0 || (total - t) % 2 != 0) 
            return 0;
        int s = (total - t ) /2;
        sort(v.begin(),v.end());
        

        vector<vector<int>> dp(n+1,vector<int>(s+1,0));
        
        dp[0][0] = 1;
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=s;j++){
                dp[i][j] = dp[i-1][j];
                if(j >= v[i-1]){
                    dp[i][j] += dp[i-1][j - v[i-1]] ;
                }
            }
        }
        
        return dp[n][s];
    }
};