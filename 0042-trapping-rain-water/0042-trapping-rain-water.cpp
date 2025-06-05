class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        // vector<int> pre(n) , suff(n);

        // pre[0] = h[0];
        // for(int i=1;i<n;i++)
        //     pre[i] = max(pre[i-1] , h[i]);

        // suff[n-1] = h[n-1];
        // for(int i = n-2;i>=0;i--)
        //     suff[i] = max(suff[i+1] , h[i]);
        int lmax = 0 , rmax = 0;
        int ans=0;
        int i = 0,j = n-1;

        while(i<j){
            int l = h[i] , r = h[j];

            if(l < r){
                if(lmax > l)
                    ans += lmax - l;

                lmax = max(lmax , l);
                i++;
            }
            else{
                if(rmax > r)
                    ans += rmax - r;
                rmax = max(rmax , r);
                j--;
            }
        }
        return ans;

        
        
    }
};