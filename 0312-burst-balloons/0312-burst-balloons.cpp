class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);  
        nums.push_back(1);             
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 0; --i) {
            for (int j = 1; j <= n + 1; ++j) {
                if(i > j )
                    continue;
                int maxi = 0;
                for (int k = i + 1; k < j; ++k) {
                    int coins = nums[i] * nums[k] * nums[j];
                    coins += dp[i][k] + dp[k][j];
                    maxi = max(maxi, coins);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[0][n + 1];
    }
};
