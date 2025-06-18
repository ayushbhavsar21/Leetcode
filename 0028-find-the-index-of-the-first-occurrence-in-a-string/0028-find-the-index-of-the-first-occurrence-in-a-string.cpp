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
    int strStr(string s, string t) {
        vector<int> v = prefix(t);
        int i =0,j=0 ;

        while(i<s.size()){
            if(t[j] == s[i]){
                i++;
                j++;
            }
            else{
                if(j != 0){
                    j = v[j-1];
                }
                else
                    i++;
            }
            if(j == t.size()){
                return  i - j;
            }
        }
        return -1;
    }
};