class Solution {
public:

    int solve(int x){
        if(x <= 1) return 1;

        for(int i = 2;i*i <= x;i++){
            if(x % i == 0)
                return x/i;
        }
        return 1;
    }
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        int prev = nums[n-1];
        for(int i = n-2;i>=0;i--){
            if(nums[i] > nums[i+1]){
                int x = nums[i];
                int op = 0;

                while(x > nums[i+1]){
                    int gcd = solve(x);
                    // cout<<gcd<<endl;

                    if(gcd == 1)
                        return -1;

                    x /= gcd ;
                    op++;
                }
                ans += op;
                nums[i] = x;
            }
        }
        return ans;
    }
};