class Solution {
public:
    string generateTag(string s) {
        string ans = "#";
        int i = 0;
        bool ok = 0;
        while(i < s.length() && ans.length() < 100){
            if(s[i] == ' '){
                if(ans.length() > 1)
                    ok = 1;
            }
            else{
                char c = s[i];
                if(ok){
                    c = toupper(c);
                    ok = 0;
                }else{
                    c = tolower(c);
                }
                ans.push_back(c);
            }
            i++;
        }
        return ans;
    }
};