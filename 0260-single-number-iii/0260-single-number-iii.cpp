class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(auto it:nums)
            x ^= it;

        unsigned int l = x & -(unsigned int)x ;
        int a1=0,a2=0;
        for(auto it:nums){
            if(it & l)
                a1 ^= it;
            else
                a2 ^= it;
        }
        vector<int> ans {a1,a2} ;
        return ans;
    }
};