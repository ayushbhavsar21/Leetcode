class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.length() == 0)
            return 0;
        int n = s.length();
        int open = 0 ;
        int ans = 0;
        for(auto it:s){
            if(it == '(')
                open++;
            else{
                if(open > 0)
                    open--;
                else
                    ans++;
            }
        }
        ans += open;
        return ans;
    }
};