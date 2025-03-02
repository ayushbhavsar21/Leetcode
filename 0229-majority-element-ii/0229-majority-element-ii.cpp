class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x1=0,x2=0,c1=0,c2=0;
        int n = nums.size();
        int l = n/3;

        for(auto it:nums){
            if(c1 == 0 && x2 != it){
                x1 = it;
                c1++;
            }
            else if(c2 == 0 && x1 != it){
                x2 = it;
                c2++;
            }
            else if(x1 == it)
                c1++;
            else if(x2 == it)
                c2++;
            else{
                c1--;
                c2--;
            }
        }
        c1 =0,c2=0;
        vector<int> ans;
        for(auto it:nums){
            if(x1 == it)
                c1++;
            else if(x2 == it)
                c2++;
        }

        if(c1 > l)
            ans.push_back(x1);
        if(c2 > l)
            ans.push_back(x2);
        return ans;

    }
};