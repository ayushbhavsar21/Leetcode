class Solution {
public:
    vector<int> prefix(string b){
        int n = b.length();
        vector<int> v(n,0);
        int j = 0;
        for(int i=1;i<n;i++){
            while(j>0 && b[i] != b[j])
                j = v[j-1];
            if(b[i] == b[j])
                j++;
            v[i] = j;
        }
        return v;
    }
    bool kmp(string s, string b){
        int n = s.length() , m = b.length();
        vector<int> v = prefix(b);
        int i =0 , j =0;
        while(i<n){
            if(s[i] == b[j]){
                i++;
                j++;
            }
            else{
                if(j!= 0)
                    j = v[j-1];
                else
                    i++;
            }
            if(j == m)
                return 1;
        }
        return 0;
    }
    int repeatedStringMatch(string a, string b) {
        string s = a;
        int count = 1;

        while(s.length() < b.length()){
            s += a;
            count++;
        }

        if(kmp(s,b)) return count;

        s += a;
        count++;

        if(kmp(s,b)) return count;

        return -1;
    }
};