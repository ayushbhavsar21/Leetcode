class Solution {
public:
    int hIndex(vector<int>& v) {
        sort(v.begin(),v.end());
        int n = v.size();
        if(v[n-1] == 0)
            return 0;
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            if(v[i] >= ans + 1)
                ans++;
            else
                return ans;
        }
        return ans == 0 ? 1:ans;
    }
};