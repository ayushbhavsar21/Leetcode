class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int i =0,j=0;
        int n = v.size();
        int sum = 0;

        int maxi = 0;

        while(j<n){
            int t = sum + v[j];
            if(t > 0){
                sum = t;
            }
            else{
                sum = 0;
            }
            while(t< sum && i<=j){
                t -= v[i];
                i++;
            }
            maxi = max(maxi , t);
            j++;
        }
        int ans = max(sum,maxi);
        if(ans == 0){
            return *max_element(v.begin(),v.end());
        }
        return ans;
    }
};