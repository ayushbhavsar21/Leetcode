class Solution {
public:
    string simplifyPath(string s) {
        stack<string> st;
        string ans = "/";
        int n = s.length();
        int i = 1;
        while(i < n){
            while (i < n && s[i] == '/') i++;

            string t = "";
            while(i< n && s[i] != '/'){
                t += s[i];
                i++;
            }
            
            if(t == ".."){
                if(!st.empty())
                        st.pop();
            }
            else if(t != "." && t.size() > 0) {
                st.push(t);
            }
           
        }
        stack<string> st2 ; 
        while(!st.empty()){
            string t = st.top();
            st.pop();
            st2.push(t);
        }
        while(!st2.empty()){
            string t = st2.top();
            st2.pop();
            ans += t;
            ans += "/";
            
        }
        if(ans.size()>1)
            ans.pop_back();
        return ans;
    }
};