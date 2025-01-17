class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int n = nums.size();
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());
        
        // Calculate bucket size and number of buckets
        int bucketSize = max(1, (maxVal - minVal) / (n - 1));
        int bucketCount = (maxVal - minVal) / bucketSize + 1;
        
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, INT_MIN);
        vector<bool> bucketUsed(bucketCount, false);
        
        // Place numbers into buckets
        for (int num : nums) {
            int bucketIndex = (num - minVal) / bucketSize;
            bucketMin[bucketIndex] = min(bucketMin[bucketIndex], num);
            bucketMax[bucketIndex] = max(bucketMax[bucketIndex], num);
            bucketUsed[bucketIndex] = true;
        }
        
        // Calculate the maximum gap
        int maxGap = 0;
        int previousMax = minVal;
        
        for (int i = 0; i < bucketCount; ++i) {
            if (!bucketUsed[i]) continue;
            maxGap = max(maxGap, bucketMin[i] - previousMax);
            previousMax = bucketMax[i];
        }
        
        return maxGap;
    }
};
