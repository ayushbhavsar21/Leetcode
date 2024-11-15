class Solution {
public:
    void solve(int i, int c, string t, string& s, vector<string>& ans) {
        if (c == 4 && i == s.length()) {
            t.pop_back();
            ans.push_back(t);
            return;
        }

       
        if (c >= 4 || i >= s.length()) return;

        
        for (int len = 1; len <= 3; ++len) {
            if (i + len > s.length()) 
                break;
            string segment = s.substr(i, len);
            int num = stoi(segment); 
            if (num > 255 || (segment[0] == '0' && segment.length() > 1))
                break;
            solve(i + len, c + 1, t + segment + '.', s, ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if (s.length() < 4 || s.length() > 12) return ans; 
        solve(0, 0, "", s, ans);
        return ans;
    }
};
