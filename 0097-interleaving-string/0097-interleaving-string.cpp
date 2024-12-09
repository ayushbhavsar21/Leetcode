class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i,int j,int k,string& s1,string& s2,string& s3){
        if(i == s1.length() && j == s2.length() && i+j == s3.length()){
            return true;
        }
        if(dp[i][j] != -1)
            return dp[i][j];
        bool r1=0,r2=0;
        if(i < s1.length() && s1[i] == s3[k]){
            r1 = solve(i+1,j,k+1,s1,s2,s3);
        }
        if(j < s2.length() && s2[j] == s3[k]){
            r2 = solve(i,j+1,k+1,s1,s2,s3);
        }

        return dp[i][j] = r1 | r2; 
    }
    bool isInterleave(string s1, string s2, string s3) {
        dp = vector<vector<int>>(s1.length() +1, vector<int>(s2.length() +1 , -1));
        return solve(0,0,0,s1,s2,s3);

    }
};