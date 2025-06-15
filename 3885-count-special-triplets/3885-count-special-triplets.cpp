#define ll long long

class Solution {
public:
    int M = 1e9 + 7;
    int specialTriplets(vector<int>& v) {
        unordered_map<int,int> suff, pre;
        int n = v.size();
        ll ans = 0;
        for(int i=0;i<n;i++){
            int x = v[i];
            suff[x]++;
        }

        for(int i=0;i<n;i++){
            suff[v[i]]--;
            int x = 2* v[i];
            ll s = pre[x];
            ll l = suff[x];

            ans = (ans + (s*l) ) % M;
            pre[v[i]] ++;            
        }
        return ans;
    }
};