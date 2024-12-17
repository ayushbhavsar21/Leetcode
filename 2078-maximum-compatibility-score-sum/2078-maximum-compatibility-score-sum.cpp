class Solution {
public:
int n,m;
    int maxCompatibilitySum(vector<vector<int>>& s, vector<vector<int>>& t) {
        n = s.size();
        m = s[0].size();

        vector<vector<int>>pre (n , vector<int>(n , 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int x = 0;
                for(int k=0;k<m;k++){
                    if(s[i][k] == t[j][k])
                        x++;
                }
                pre[i][j] = x;
            }
        }
        vector<int> dp ((1<<n) , -1);

        return solve(0 , 0 , pre , dp);
    }
    int solve(int idx, int mask , vector<vector<int>>& pre ,vector<int>& dp){
        if(idx == n)
            return 0;

        if(dp[mask] != -1)
            return dp[mask];

        int ans =0 ;
        for(int i=0;i<n;i++){
            if(!(mask & (1<<i))){
                
                ans = max(ans , pre[idx][i] + solve(idx + 1 , (mask | (1<<i)) , pre , dp));
                
            }
        }
        return ans;
    }
};