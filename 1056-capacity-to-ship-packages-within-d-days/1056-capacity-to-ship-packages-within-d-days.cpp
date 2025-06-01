class Solution {
public:
    int shipWithinDays(vector<int>& v, int days) {
        int n = v.size();
        int n2 = (n + 1)/ days;

        int s = *max_element(v.begin(),v.end()) ;
        int e = accumulate(v.begin(),v.end(),0) ;
        int mid = s+ (e - s)/2;
        int ans = e;
        

        while(s<=e){
            mid = s+ (e - s)/2;
            int c= 1;
            int w = 0;
            for(int i=0;i<n;i++){
                if(w + v[i] > mid){
                    c++;
                    w=0;
                }
                w += v[i];
            }
            if(c > days)
                s = mid+1;
            else{
                e = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};