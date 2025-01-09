class Solution {
public:
    bool ispal(string s){
        int b = 0;
        int e = s.length() -1 ;
        while(b<=e){
            if(s[b] != s[e])
                return false;

            b++;
            e--;
        }
        return true;
    }
    void solve(int i,string s, vector<vector<string>>& ans, vector<string>&temp){
        if(i == s.length()){
            ans.push_back(temp);
            return ;
        }
        string x ="" ;
        for(int j =i;j<s.length();j++){
            x += s[j];
            if(ispal(x)){
                temp.push_back(x);
                solve(j + 1 , s ,ans ,temp);
                temp.pop_back();
            }
        }
            
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;
        solve(0 , s , ans , temp);
        return ans;
    }
};