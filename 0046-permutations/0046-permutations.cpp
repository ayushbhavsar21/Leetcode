class Solution {
public:
    void solve(vector<int>& nums,vector<int>& v,vector<vector<int>>& ans ,unordered_set<int>& st ){
        if(v.size() == nums.size()){
            ans.push_back(v);
        }
        for(int i=0;i<nums.size();i++){
            if(!st.count(i)){
                st.insert(i);
                v.push_back(nums[i]);
                solve(nums,v,ans,st);
                st.erase(i);
                v.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> st;
        vector<vector<int>> ans;
        vector<int> v;

        solve(nums,v,ans,st);
        return ans;
    }
};