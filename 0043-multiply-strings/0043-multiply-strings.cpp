class Solution {
public:
    string multiply(string n1, string n2) {
        
        reverse(n1.begin(), n1.end());
        reverse(n2.begin(), n2.end());

        vector<int> v(n1.length() + n2.length(), 0);
        
        
        for (int i = 0; i < n1.length(); i++) {
            int x = n1[i] - '0';
            for (int j = 0; j < n2.length(); j++) {
                int y = n2[j] - '0';
                int product = x * y;
                int sum = product + v[i + j]; 
                
                v[i + j] = sum % 10;
                v[i + j + 1] += sum / 10; 
            }
        }
        
        string ans;
        for (int i = v.size() - 1; i >= 0; i--) {
            if (!(ans.empty() && v[i] == 0)) {
                ans.push_back(v[i] + '0');
            }
        }

        return ans.empty() ? "0" : ans;
    }
};


