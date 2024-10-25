class Solution {
public:
    void print(vector<int>& nums){
        for(auto it:nums)
            cout<<it<<" ";
        cout<<endl;
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int idx = -1  ;  

        // print(nums);
        
        for ( int i = n-2 ; i >= 0 ; i-- ) 
        {
            if (nums[i] < nums[i+1] ) 
            {
                idx = i ; 
                break ; 
            }
        }  
        if (idx == -1 ) 
        {
            reverse(nums.begin(),nums.end()) ;
            return ;
        }
        // print(nums);
        
        reverse(nums.begin()+idx+1,nums.end()) ;

        // print(nums);
        
        int j = -1 ; 
        for ( int i = idx+1 ; i < n ; i++ )
        {
              if ( nums[i] > nums[idx])
              {
                j = i ; 
                break ; 
              }
        }
        
        int temp = nums[idx] ;
        nums[idx] = nums[j] ;
        nums[j] = temp ;

        // print(nums);

        return ; 
    }
};