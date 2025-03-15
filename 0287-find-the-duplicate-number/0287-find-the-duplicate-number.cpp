class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> st;
        for(auto it:nums){
            if(st.count(it))
                return it;
            else
                st.insert(it);
        }
        return -1;
    }

};