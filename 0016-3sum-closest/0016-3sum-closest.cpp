class Solution {
public:
    int threeSumClosest(vector<int>& v, int t) {
        int n = v.size();
        sort(v.begin(),v.end());
        int mind = INT_MAX;
        int ans = -1;

        for(int i=0;i<n-2;i++){
            int l = i+1 , r = n-1;
            while(l < r){
                int sum = v[i] + v[l] + v[r];
                if(mind > abs(t - sum)){
                    mind = abs(t - sum);
                    ans = sum;
                }
                if(sum == t){
                    return sum;
                }
                else if(sum > t)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};