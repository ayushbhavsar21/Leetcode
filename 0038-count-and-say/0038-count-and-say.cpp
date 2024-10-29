class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        if(n==1)
            return s;
        n--;
        while(n--){
            // cout<<"#"<<endl;
            int i = 0;
            int freq = 0;
            char pre;
            string t ="";
            while(i<s.length()){
                // cout<<"$"<<endl;
                if(i==0){
                    freq++;
                    pre = s[i];
                }
                else{
                    // cout<<"%"<<endl;
                    if(pre == s[i])
                        freq++;
                    else{
                        t.push_back(freq + '0');
                        t.push_back(pre);                        

                        pre = s[i];
                        freq = 1;
                    }
                }
                i++;
            }
            t.push_back(freq + '0');
            t.push_back(pre);
            // cout<<t<<endl;
            s = t;
        }
        return s;
    }
};