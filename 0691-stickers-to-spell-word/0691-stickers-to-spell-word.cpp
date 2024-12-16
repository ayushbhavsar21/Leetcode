class Solution {
public:
    int minStickers(vector<string>& s, string t) {
        int n = t.size();
        int mask = (1 << n) - 1;

        vector<vector<int>> freq;
        for (auto it : s) {
            vector<int> v(26, 0);
            for (auto it2 : it) {
                v[it2 - 'a']++;
            }
            freq.push_back(v);
        }
        vector<int> memo((1<<15) + 1 , -1);
        memo[0] = 0;
        int result = dfs(mask, freq, t, memo);
        return result == INT_MAX ? -1 : result;
    }
    int dfs(int mask, vector<vector<int>>& freq, string& t,
            vector<int>& memo) {
        
        if (memo[mask] != -1)
            return memo[mask];
        int res = INT_MAX;

        for (auto it : freq) {
            int newMask = mask;

            vector<int> temp = it;
            for (int i = 0; i < t.size(); i++) {
                if ((mask >> i) & 1) {
                    char c = t[i];
                    if (it[c - 'a'] > 0) {
                        newMask &= ~(1 << i);
                        it[c - 'a']--;
                    }
                }
            }

            it = temp;
            if (newMask < mask) {
                int x = dfs(newMask, freq, t, memo);
                if (x != INT_MAX)
                    res = min(res, 1 + x);
            }
        }

        return memo[mask] = res;
    }
};