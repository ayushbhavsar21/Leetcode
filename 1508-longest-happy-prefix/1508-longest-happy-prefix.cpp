class Solution {
public:
    vector<int> prefix(string s){
        int n = s.length();
        vector<int> v(n,0);
        int j = 0;
        for(int i=1;i<n;i++){
            while(j >0 && s[i] != s[j])
                j = v[j-1];
            if(s[i] == s[j])
                j++;
            v[i] = j;
        }
        return v;
    }
    string longestPrefix(string s) {
        vector<int> v = prefix(s);
        
        int n = s.length();
        string ans = s.substr(n-v.back());

        return ans;
    }
};