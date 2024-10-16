class Solution {
public:
    void solve(int l,int r, int n,string& s, vector<string> &ans){
        if(l > n || r > n)
            return ;
        if(l == n && r== n){
            ans.push_back(s);
            return;
        }
        if(l > r){
            s.push_back(')');
            solve(l , r+1 ,n, s , ans );
            s.pop_back();
        }
        s.push_back('(');
        solve(l+1 , r , n , s ,ans);
        s.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s="";
        solve(0 ,0 ,n ,s ,ans);
        return ans;
    }
};