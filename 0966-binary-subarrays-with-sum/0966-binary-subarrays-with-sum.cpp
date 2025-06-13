class Solution {
public:
    int numSubarraysWithSum(vector<int>& v, int t) {
        int ans = 0;
        int n = v.size();
        int sum = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<n;i++){
            sum += v[i];

            if(mp.find(sum - t) != mp.end())
                ans += mp[sum - t];

            mp[sum] ++;
        }
        return ans;
        
        return ans;
    }
};