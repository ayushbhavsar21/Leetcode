class Solution {
public:
    void solve(int i,vector<int>&v,vector<int>& c, int t,vector<vector<int>>& ans){
        if(i>=c.size()){
            if(t == 0)
                ans.push_back(v);
            return ;
        }
        if(c[i] <= t){
            v.push_back(c[i]);
            solve(i , v , c , t - c[i] , ans );
            v.pop_back();
        }
        solve(i + 1 , v , c , t  , ans );

        return ;

    }
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> v;

        solve(0 , v , c , t , ans);
        return ans;

    }
};