class Solution {
public:
    int lis(vector<int>& arr) {
        int n = arr.size();
        vector<int> v;
        v.push_back(arr[0]);
        for(int i=1;i<n;i++){
            if(v.back() < arr[i])
                v.push_back(arr[i]);
            else{
                int ind = lower_bound(v.begin(),v.end(),arr[i]) - v.begin();
                v[ind] = arr[i];
            }
        }
        return v.size();
    }
    int lengthOfLIS(vector<int>& nums) { return lis(nums); }
};