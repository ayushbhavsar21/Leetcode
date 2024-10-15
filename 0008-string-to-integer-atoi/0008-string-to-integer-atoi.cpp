class Solution {
public:
    bool ok =0;

    void solve(int i,string s,int &result){
        if(i >= s.length()){
            return;
        }
        if(!isdigit(s[i]))
            return ;

        int x = s[i] - '0';
        if(result > (INT_MAX -x)/10){
            result = INT_MAX;
            ok = 1;
            return ;
        }
        result = result*10 + x;
        solve(i+1 , s , result);
    }
    int myAtoi(string s) {
        int n = s.length();
        int i = 0;
        int sign = 1;
        while(s[i] == ' '){
            i++;
        }
        if(s[i] == '-'){
            sign = -1;
            i++;
        } 
        else if(s[i] == '+') i++;

        int result = 0;
        solve(i , s , result);

        if(ok){
            if(sign == -1)
                return INT_MIN;
            else
                return INT_MAX;
        }
        return sign * result ;

    }
};