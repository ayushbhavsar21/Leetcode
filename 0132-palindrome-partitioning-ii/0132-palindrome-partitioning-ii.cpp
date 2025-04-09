class Solution {
public:
    bool check(int s,int e,string& s1,vector<vector<int>>& pal){
        if(s >= e)
            return 1;
        if(pal[s][e] != -1)
            return pal[s][e];
        if(s1[s] == s1[e] ){
            return pal[s][e] = check(s+1,e-1,s1,pal);
        }
        return pal[s][e] = 0;
    }
    int solve(int i,int j,string& s,vector<vector<int>>& dp,vector<vector<int>>& pal){
        if(i >= j) return 0;

        if(check(i,j,s,pal))
            return dp[i][j] = 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;
        for(int k= i;k<=j;k++){
            if(check(i,k,s,pal)){
                int temp = 1 + solve(k+1,j,s,dp,pal);
                mini = min(mini,temp);
            }
        }
        return dp[i][j] = mini;
    }
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>>dp (n+1,vector<int>(n+1,-1));
        vector<vector<int>>pal (n+1,vector<int>(n+1,-1));
        return solve(0,n-1,s,dp,pal);
    }
};