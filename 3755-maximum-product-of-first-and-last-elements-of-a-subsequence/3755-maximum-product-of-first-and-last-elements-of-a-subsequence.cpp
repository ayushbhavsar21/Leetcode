#define ll  long long
class Solution {
public:
    long long maximumProduct(vector<int>& v, int m) {
        ll ans = LLONG_MIN;
        int n = v.size();
        vector<int> suff(n) , suff2(n);
        suff[n-1] = v[n-1];
        suff2[n-1] = v[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = max(suff[i+1] , v[i]);
            suff2[i] = min(suff2[i+1] , v[i]);
        }

        // for(auto it:suff)
        //     cout<<it<<" ";
        // cout<<endl;
        // for(auto it:suff2)
        //     cout<<it<<" ";
        // cout<<endl;

        for(int i=0;i<=n-m;i++){
            ll x = (ll)v[i] * (ll)suff[i+m-1];
            ll y = (ll)v[i] * (ll)suff2[i+m-1];
            // cout<< x<<" "<<y<<endl;
            ans = max({ans,x,y});
        }
        return ans;
    }
};