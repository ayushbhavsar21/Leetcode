class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n = nums.size();
        int minLength = INT_MAX; // To track the minimum length
        int currentSum = 0;      // To track the current sum of the window
        int start = 0;           // Start of the sliding window

        for (int end = 0; end < n; ++end) {
            currentSum += nums[end];

            // Shrink the window from the left as long as the sum is >= t
            while (currentSum >= t) {
                minLength = min(minLength, end - start + 1);
                currentSum -= nums[start];
                ++start;
            }
        }

        // If no subarray is found, return 0
        return minLength == INT_MAX ? 0 : minLength;
    }
};
