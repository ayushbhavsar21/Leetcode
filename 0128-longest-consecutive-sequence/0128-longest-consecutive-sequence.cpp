class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(),nums.end());
        int ans = 0;

        for(auto it:st){
            if(!st.count(it - 1)){
                int c=0,j=0;
                while(st.count(it + j)){
                    c++;
                    j++;
                }
                ans= max(c , ans);
            }
        }
        return ans;
    }
};