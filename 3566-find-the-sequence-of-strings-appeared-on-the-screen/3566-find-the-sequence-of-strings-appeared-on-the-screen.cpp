class Solution {
public:
    vector<string> stringSequence(string t) {
        vector<string> ans;

        int n = t.length();
        if (n == 0)
            return ans;
        string s = "a";
        int i = 0;
        while (s.length() <= n) {
            if (s[i] == t[i]) {
                ans.push_back(s);
                i++;
                s.push_back('a');

            } else {
                ans.push_back(s);
                s[i] = s[i] + 1;
            }
        }
        return ans;
    }
};