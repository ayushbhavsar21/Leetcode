class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = nums[0];
        int prev2 = 0;
        int n = nums.size();

        for(int i=1;i<n;i++ ){
            int c = prev1 ;
            prev1 = max(nums[i] + prev2 , prev1);
            prev2 = c;
        }
        return prev1;
    }
};