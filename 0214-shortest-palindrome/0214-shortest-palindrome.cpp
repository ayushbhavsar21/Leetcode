class Solution {
public:
    vector<int> prefix(string s){
        int n = s.length();
        vector<int> v(n,0);
        int j = 0;
        for(int i=1;i<n;i++){
            while(j>0 && s[i] != s[j])
                j = v[j-1];
            if(s[i] == s[j])
                j++;
            v[i] = j;
        }
        return v;
    }
    string shortestPalindrome(string a) {
        string b = a;
        reverse(b.begin(),b.end());
        string s = a + '#' + b;
        vector<int> v = prefix(s);

        int c = v.back();
        return b.substr(0,b.length() - c) + a;

    }
};