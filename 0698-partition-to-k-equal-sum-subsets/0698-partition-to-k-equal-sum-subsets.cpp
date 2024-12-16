class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum%k != 0 )
            return 0;

        int s = sum/k;

        sort(nums.rbegin(),nums.rend());
        if(nums[0] > s)
            return 0;

        unordered_map<int,bool> memo;

        return solve(0 , 0 , s , nums , k , memo);


    }

    bool solve(int used,int curr,int& s,vector<int>& nums, int k,unordered_map<int,bool>& memo){
        if(k == 0)
            return true;

        if(memo.count(used))
            return memo[used];

        for(int i=0;i<nums.size();i++){
            int bit = 1<<i;

            if((used & bit) == 0){
                int sum = curr + nums[i];
                if(sum == s){
                    if(solve(used | bit , 0 , s ,  nums , k - 1 , memo))
                        return memo[used] = 1;
                }
                else if(sum < s){
                    if(solve(used | bit , sum , s ,  nums , k , memo))
                        return memo[used] = 1;
                }
            }
        }
        return memo[used] = 0;
    }
};