class Solution {
public:
    int solve(int k, vector<int>& v) {
        unordered_map<int, int> mp;
        int l = 0, n = v.size(), ans = 0;

        for (int i = 0; i < n; i++) {
            mp[v[i]]++;

            while (mp.size() > k) {
                mp[v[l]]--;
                if (mp[v[l]] == 0)
                    mp.erase(v[l]);
                l++;
            }

            ans += (i - l + 1);  
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& v, int k) {
        return solve(k, v) - solve(k - 1, v);
    }
};
