class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ans, int mid ){
        int l = mid,r = mid;

        while(l>=0 && nums[l] == nums[mid]){
            l-- ;
        }
        ans[0] = (l+1);
        while(r < nums.size() && nums[r] == nums[mid]){
            r++ ;
        }
        ans[1] = (r-1);

        return ;
    }
    vector<int> searchRange(vector<int>& nums, int t) {
        int n = nums.size();

        if(nums.size() == 0 )
            return {-1,-1};
        if(nums[n-1] < t)
            return {-1,-1};

        // if(n == 1 && nums[n-1] == t){
        //     return {0,0};
        // }

        vector<int> ans ;
        ans.push_back(-1);
        ans.push_back(-1);
        int s =0 , e= n-1 , mid = s + (e-s)/2;
        while(s <= e){
            mid = s + (e-s)/2;
            if(nums[mid] == t){
                solve(nums , ans , mid);
                return ans;
            }
            else if(nums[mid] > t )
                e = mid - 1;
            else{
                s = mid + 1;
            }
        }
        return ans;
    }
};