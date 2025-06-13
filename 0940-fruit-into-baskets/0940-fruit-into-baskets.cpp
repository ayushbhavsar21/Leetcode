class Solution {
public:
    int totalFruit(vector<int>& v) {
        unordered_map<int, int> mp;
        int s = 0, ans = 0;

        for (int e = 0; e < v.size(); ++e) {
            mp[v[e]]++;

            while (mp.size() > 2) {
                mp[v[s]]--;
                if (mp[v[s]] == 0)
                    mp.erase(v[s]);
                s++;
            }

            ans = max(ans, e - s + 1);
        }

        return ans;
    }
};
