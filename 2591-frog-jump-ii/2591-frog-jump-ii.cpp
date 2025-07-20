class Solution {
public:
    int maxJump(vector<int>& v) {
        int n = v.size();
        int ans = v[1] - v[0];
        for(int i=2;i<n;i++){
            ans = max(ans, v[i] - v[i-2]);
        }
        ans = max(ans, v[n-1] - v[n-2]);
        return ans;
    }
};