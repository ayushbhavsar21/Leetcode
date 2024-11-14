class Solution {
public:
    void solve(int i, vector<vector<int>>&ans, vector<int> v, vector<int>& nums){
        if(i >= nums.size()){
            ans.push_back(v);
            return;
        }
        
        v.push_back(nums[i]);
        solve(i+1  ,ans ,v ,nums);
        v.pop_back();
        
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(i+1 , ans ,v, nums);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> v;
        solve(0 , ans , v ,nums);
        return ans;
    }
};