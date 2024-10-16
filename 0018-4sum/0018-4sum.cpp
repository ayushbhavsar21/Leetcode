#define ll long long int
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int t) {
        int n = nums.size();
        vector<vector<int>>  ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int l = j+1,r = n-1;
                while(l < r){
                    long long int sum = (ll)nums[i] + (ll)nums[j] + (ll)nums[l] + (ll)nums[r];

                    if(sum == (ll)t){
                        ans.push_back({nums[i] , nums[j] , nums[l] , nums[r]});
                        l++;
                    }
                    else if(sum > t)
                        r--;
                    else
                        l++;
                }
            }
        }


        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()) , ans.end());
        return ans;


    }
};