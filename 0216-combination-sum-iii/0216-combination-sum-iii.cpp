class Solution {
public:
    void solve(int k,int n,int s,vector<int>& v,vector<vector<int>>& ans){
        if(k ==0 && n == 0){
            ans.push_back(v);
            return;
        }
        if(k<0 || n<0)
            return;
        for(int i=s+1;i<10;i++){
            v.push_back(i);
            solve(k-1,n-i,i,v,ans);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        for(int i=1;i<10;i++){
            v.push_back(i);
            solve(k-1,n-i,i,v,ans);
            v.pop_back();
        }
        return ans;
    }
};