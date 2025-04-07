class Solution {
public:
    static bool cmp(string& s1,string& s2){
        return s1.size() < s2.size();
    }
    bool check(string& s1,string& s2){
        if(s1.length() != s2.length() +1)
            return 0;
        int f = 0,s = 0;
        bool ok = 1;
        while(f < s1.size()){
            if(s1[f] == s2[s]){
                f++;s++;
            }
            else if(ok){
                f++;
                ok =0;
            }
            else
                return 0;
        }
        return 1;

    }
    int longestStrChain(vector<string>& v) {
        int n = v.size();
        sort(v.begin(),v.end(),cmp);
        for(auto it:v)
            cout<<it<<" ";

        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(v[i],v[j])){
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(),dp.end());
    }
};