class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp (n+1 , vector<int>(m+1 , 0));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        int l = dp[n][m] ; 
        string s = "";

        int i = n,j = m;
        while(i>0 && j>0){
            if(s1[i-1] == s2[j-1]){
                s += s1[i-1];
                i--;
                j--;
            }
            else {
                if(dp[i-1][j] > dp[i][j-1] ){
                    i--;
                }
                else{
                    j--;
                }

            }
        }
        reverse(s.begin(),s.end());

        // cout<<s<<endl;

        i = 0;
        j = 0;
        int index = 0;
        string ans = "";
        while(i<n && j<m && index <l){

            if(s1[i] == s[index] && s2[j] == s[index]){
                ans += s[index];
                index++;
                i++;
                j++;
            }
            else{
                if(s1[i] != s[index] ){
                    ans += s1[i];
                    i++;
                }
                if(s2[j] != s[index] ){
                    ans += s2[j];
                    j++;
                }     
            }       
        }
        while(i<n){
            ans += s1[i];
            i++;
        }
        while(j<m){
            ans += s2[j];
            j++;
        }
        return ans;
    }
};