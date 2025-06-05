class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        int n = num.size();
        
        for(int i = 0; i < n; i++) {
            while(!st.empty() && st.top() > num[i] && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }
        
        string ans = "";
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        int i = ans.length() -1;
        while(i>=0 && ans[i] == '0'){
            ans.pop_back();
            i--;
        }
        reverse(ans.begin(), ans.end());
        
        if(ans.empty()) {
            return "0";
        }
        
        return ans;
    }
};
