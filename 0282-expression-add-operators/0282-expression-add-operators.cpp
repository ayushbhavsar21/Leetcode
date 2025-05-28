class Solution {
public:
    string s;
    int t;
    void solve(int i,string path,long sum,long prev,vector<string>& ans){
        if(i == s.length()){
            if(sum == t)
                ans.push_back(path);
            return ;
        }
        string s2 = "";
        long sum2 = 0;

        for(int j=i;j<s.length();j++){
            if(j > i && s[i] == '0') break;

            s2 += s[j];
            sum2 = sum2*10 + (s[j] - '0');

            if(i == 0)
                solve(j+1, s2 , sum2 , sum2 , ans);
            else{
                solve(j+1,path +"+" + s2 , sum + sum2 , sum2 , ans);
                solve(j+1,path +"-" + s2 , sum - sum2 , -sum2 , ans);
                solve(j+1,path +"*" + s2 , sum - prev + prev * sum2 ,prev*sum2 , ans);

            }
        }
    }
    vector<string> addOperators(string num, int target) {
        s = num;
        t = target;
        vector<string> ans;
        solve(0,"",0,0,ans);
        return ans;
    }
};  