class Solution {
public:
    int search(vector<int>& nums, int t) {
        int s = 0;
        int e = nums.size() - 1;
        int mid = s + (e - s)/2;
        while(s<=e){
            mid = s + (e - s)/2;

            if(nums[mid] == t)
                return mid;
            
            else if(nums[s]<= nums[mid]){
                if(nums[s]<=t && nums[mid]>t){
                    e = mid -1;
                }
                else{
                    s = mid +1;
                }
            }
            else{
                if(nums[mid]<t && t<=nums[e]){
                    s = mid +1;
                }
                else{
                    e = mid -1;
                }
            }
        }
        return -1;
    }
};