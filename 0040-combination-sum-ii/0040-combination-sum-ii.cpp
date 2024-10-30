class Solution {
public:
    void solve(int i,vector<int>&v , int t, vector<int>& c,vector<vector<int>> &ans ){
        if(i >= c.size()){
            if(t == 0)
                ans.push_back(v);
            return ;
        }
        if(c[i] <= t){
            v.push_back(c[i]);
            solve(i+1 , v , t - c[i] , c ,ans);
            v.pop_back();
        }
        while(i+1 < c.size() && c[i] == c[i+1])
            i++;
        solve(i+1 , v , t , c ,ans);
    }
    vector<vector<int>> combinationSum2(vector<int>& c, int t) {
        vector<vector<int>> ans;
        vector<int> v;
        sort(c.begin(),c.end());

        solve(0 , v , t , c , ans);
        return ans;

    }
};