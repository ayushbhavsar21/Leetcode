class Solution {
public:
    int maxProfit(vector<int>& v) {
        v.push_back(0);
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int ans = 0;

        for(int i=0;i<v.size();i++){
            if(v[i] < maxi ){
                ans += maxi - mini;
                mini = INT_MAX;
                maxi = INT_MIN;
            }
            mini = min(v[i] , mini );
            maxi = max(v[i] , maxi );
        }

        return ans;
    }
};