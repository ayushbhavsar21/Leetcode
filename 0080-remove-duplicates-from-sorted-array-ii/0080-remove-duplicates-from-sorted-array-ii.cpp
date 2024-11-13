class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int x = nums[n-1];
        int c = 1;

        for(int i=n-2;i>=0;i--){
            if(nums[i] == x){
                if(c>=2){
                    nums.erase(nums.begin() + i);
                }
                else
                    c++;
            }
            else{
                x = nums[i];
                c = 1;
            }
        }
        return nums.size();
    }
};