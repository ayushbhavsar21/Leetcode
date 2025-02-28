class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        stack<int> st;
        char sign = '+';
        int num = 0;
        
        for (int i = 0; i < n; i++) {
            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == n - 1) {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    int top = st.top();
                    st.pop();
                    st.push(top * num);
                } else if (sign == '/') {
                    int top = st.top(); 
                    st.pop();
                    st.push(top / num);
                }
                sign = s[i];
                num = 0;
            }
        }
        
        int ans = 0;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        
        return ans;
    }
};
