class Solution {
public:
    int minEatingSpeed(vector<int>& p, int h) {
        int n = p.size();

        if(n>h)
            return -1;

        int s = 1 , e = *max_element(p.begin(),p.end());
        int mid = s + (e - s)/2 ;
        int ans = e;

        while(s<=e){
            mid = s + (e - s)/2 ;
            int t = 0;
            bool ok = 1;
            for(int i=0;i<n;i++){
                int t2 = ceil((double)p[i] / (double) mid);
                t += t2;
                if(t > h){
                    ok =0;
                    break;
                }
            }
            if(ok){
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};