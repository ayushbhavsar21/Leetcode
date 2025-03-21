class Solution {
public:
    string getHint(string s, string g) {
        int x = 0,y = 0 ,n = s.length();
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(s[i] == g[i]){
                x++;
                g[i] = '_';
            }
            else{
                mp[s[i]] ++;
            }
        }
        for(int i=0;i<n;i++){
            if(mp[g[i]] > 0){
                y++;
                mp[g[i]] --;
            }
        }
        string ans;
        string sx = to_string(x); ;
        ans += sx;
        ans += 'A';
        string sy = to_string(y); ;
        ans += sy;
        ans += 'B';
        return ans;
    }
};