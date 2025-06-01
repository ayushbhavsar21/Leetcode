class Solution {
public:
    int minDays(vector<int>& v, int m, int k) {
        int n = v.size();
        if((long long )n <  (long long)m * (long long)k)
            return -1;

        int s = *min_element(v.begin(),v.end());
        int e = *max_element(v.begin(),v.end());
        int mid = s + (e - s)/2;

        int ans = e;

        while(s <= e){
            mid = s + (e - s)/2;
            bool ok = 1;
            int i = 0 , j = 0;
            while(i < m){
                int c = 0;
                while(c < k && j<n){
                    if(v[j] <= mid){
                        c++;
                    }
                    else{
                        c= 0;
                    }
                    j++;
                }
                if(c == k)
                    i++;
                if(j >= n && i != m){
                    ok = 0;
                    break;
                }
            }
            if(ok){
                ans = mid;
                e = mid-1;
                // cout<<ans<<endl;
            }
            else
                s = mid+1;

            
        }
        return ans;
    }
};