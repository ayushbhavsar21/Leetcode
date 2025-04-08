class Solution {
public:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) {
            return 0;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int maxi = INT_MIN;
        for (int k = i; k <= j; k++) {
            int prev = (i == 0) ? 1 : nums[i - 1];
            int next = (j == nums.size() - 1) ? 1 : nums[j + 1];
            int temp = (prev * nums[k] * next) + solve(i, k - 1, nums, dp) + solve(k + 1, j, nums, dp);
            maxi = max(maxi, temp);
        }
        return dp[i][j] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(0, n - 1, nums, dp);
    }
};
