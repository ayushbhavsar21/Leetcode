class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& v, vector<int>& add) {
        int n = v.size();
        vector<vector<int>> ans;
        int i = 0;

        while (i < n && v[i][1] < add[0]) {
            ans.push_back(v[i]);
            i++;
        }


        while (i < n && v[i][0] <= add[1]) {
            add[0] = min(add[0], v[i][0]);
            add[1] = max(add[1], v[i][1]);
            i++;
        }
        ans.push_back(add); 

        while (i < n) {
            ans.push_back(v[i]);
            i++;
        }

        return ans;
    }
};
