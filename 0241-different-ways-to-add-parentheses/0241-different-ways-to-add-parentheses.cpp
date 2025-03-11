class Solution {
public:
    
    vector<int> diffWaysToCompute(string s) {
        vector<int> ans;
        int n = s.length();
        
        for(int i=0;i<n;i++){

            if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
                vector<int> left = diffWaysToCompute(s.substr(0,i));
                vector<int> right = diffWaysToCompute(s.substr(i+1,n));

                for(auto l:left){
                    for(auto r:right){
                        if (s[i] == '+') ans.push_back(l + r);
                        else if (s[i] == '-') ans.push_back(l - r);
                        else if (s[i] == '*') ans.push_back(l * r);
                    }
                }
            }
        }
        if(ans.empty()) ans.push_back(stoi(s));
        return ans;
    }
};