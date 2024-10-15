class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin(), v.end());
        int n = v.size();
        
        for (int i = 0; i < n - 2; ++i) {
            
            if (i > 0 && v[i] == v[i - 1]) continue;

            int l = i + 1;      
            int r = n - 1;      

            while (l < r) {
                int sum = v[i] + v[l] + v[r];
                
                if (sum == 0) {
                    ans.push_back({v[i], v[l], v[r]});
                    l++;
                    r--;

                    
                    while (l < r && v[l] == v[l - 1]) l++;
                    while (l < r && v[r] == v[r + 1]) r--;
                } 
                else if (sum < 0) {
                    l++;
                } 
                else {
                    r--; 
                }
            }
        }
        // sort(ans.begin(),ans.end());
        // ans.erase(unique(ans.begin(),ans.end()) , ans.end());
        return ans;
    }
};
