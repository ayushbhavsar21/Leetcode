class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p = 1;
        vector<int> ans(nums.size() , 0);
        int zero = 0;
        int index = -1;
        int i = 0;
        for(auto it:nums ){
            if(it == 0){
                zero++;
                index = i;
                if(zero > 1)
                    return ans;
            }
            else{
                p *= it;
            }
            i++;
        }
        if(zero){
            ans[index] = p;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            ans[i] = p/ (nums[i]);
        }
        return ans;
    }
};