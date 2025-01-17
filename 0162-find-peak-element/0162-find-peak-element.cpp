class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1 || nums[0] > nums[1])
            return 0;
        int n = nums.size();
        if(nums[n-1] > nums[n-2])
            return n-1;
        
        int s= 0,e = n-1;
        int mid = s + ( e - s)/2;

        while(s<e){
            mid = s + ( e - s)/2;
            if(nums[mid] > nums[mid+1] )
                e = mid;
            else
                s = mid+1;
        }
        return s;
    }
};