class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int l = n/3;
        // int maxi = *max_element(nums.begin(),nums.end());
        // int mini = *min_element(nums.begin(),nums.end());
        vector<int> ans ;
        unordered_map<int,int> mp ;
        for(auto it:nums)
            mp[it]++;
        for(auto it:mp){
            if(it.second > l)
                ans.push_back(it.first);
        }
        return ans;
    }
};