class Solution {
public:
    int solve(int i,int j, vector<vector<int>>& v , vector<vector<int>>& dp){
        if(i >= v.size()){
            return 0;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = v[i][j];
        int r1 = solve(i+1 , j , v , dp);
        int r2 = solve(i+1 , j + 1 , v , dp);
        ans = ans + min(r1 , r2);
        return dp[i][j] = ans;
    }
    int minimumTotal(vector<vector<int>>& v) {
        vector<vector<int>> dp (v.size()+1 , vector<int> (v[v.size()-1].size() + 1 , -1));

        return solve(0 , 0 , v , dp);
    }
};