class Solution {
public:
    int minCost(int n, vector<int>& v) {
        v.push_back(n);
        v.push_back(0);
        sort(v.begin(),v.end());
        int m = v.size();
        vector<vector<int>> dp(m , vector<int>(m , 0));
        for(int i=m-2;i>0;i--){
            for(int j=1;j<m-1;j++){
                if(i > j) continue;
                int mini = INT_MAX;
                for(int k=i;k<=j;k++ ){
                    int temp = v[j+1] - v[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(temp , mini);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m-2];
    }
};