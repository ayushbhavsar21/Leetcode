class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp1;
        for(auto it:t)
            mp1[it]++;

        int r = mp1.size();
        int l = 0 , c = 0 , ans = INT_MAX , index = 0;
        unordered_map<char,int> mp2;

        for(int i=0;i<s.length();i++){
            mp2[s[i]]++;

            if(mp1.count(s[i]) && mp1[s[i]] == mp2[s[i]])
                c++;

            while(c == r && l <= i){

                if(ans > (i - l + 1) ){
                    ans =  (i - l + 1);
                    index = l;
                }

                mp2[s[l]] --; 

                if(mp1.count(s[l]) && mp1[s[l]] > mp2[s[l]])
                    c--;

                l++;
            }
        }
        return ans == INT_MAX ? "" : s.substr(index , ans);
    }
};