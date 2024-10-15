class Solution {
public:

    int convert(char c){
        if(c=='I') return 1;
        else if(c=='V') return 5;
        else if(c=='X') return 10;
        else if(c=='L') return 50;
        else if(c=='C') return 100;
        else if(c=='D') return 500;
        else if(c=='M') return 1000;

        return 0;
    }
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            int x = convert(s[i]);

            if(i>0 && (s[i] =='V' || s[i] =='X') && s[i-1] == 'I'){
                x-= 2;
            }
            else if(i>0 && (s[i] =='L' || s[i] =='C') && s[i-1] == 'X'){
                x-= 20;
            }
            else if(i>0 && (s[i] =='D' || s[i] =='M') && s[i-1] == 'C'){
                x-= 200;
            }
            // cout<<x<<endl;
            ans += x;
        }
        return ans;
    }
};