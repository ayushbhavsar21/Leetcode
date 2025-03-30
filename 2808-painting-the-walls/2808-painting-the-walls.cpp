class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i,int walls,vector<int>& cost, vector<int>& t){
        if(walls <= 0)
            return 0;
        if(i>= cost.size())
            return 1e9;

        if(dp[i][walls] != -1)
            return dp[i][walls];

        dp[i][walls] = min(solve(i+1,walls,cost,t) , cost[i] + solve(i+1,walls - t[i] - 1 , cost , t));
        return dp[i][walls];

        
    }
    int paintWalls(vector<int>& cost, vector<int>& t) {
        int n = cost.size();
        dp = vector<vector<int>> (n+1,vector<int>(n+1 ,-1));
        return solve(0 , n , cost , t );
    }
};