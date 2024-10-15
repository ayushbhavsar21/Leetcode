class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 1)
            return 1;
        int l=0,r=0;
        unordered_set<char> st;
        int maxi = 0;
        while(r<n){
            if(st.count(s[r]) == 0){
                st.insert(s[r]);
                r++;
            }
            else{
                maxi = max(maxi  , (r - l ));
                while(st.count(s[r])!= 0){
                    st.erase(s[l]);
                    l++;
                }
            }
        }
        maxi = max(maxi , (r - l) );
        return  maxi;
    }
};