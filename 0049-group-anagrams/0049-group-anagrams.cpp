class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& v) {
        unordered_map<string,vector<string>> mp;

        for(auto it:v){
            vector<int> count(26, 0);
            for(auto c:it){
                count[c - 'a'] ++;
            }
            // string hash = "";
            // for(auto x:count){
            //     hash += "#" + to_string(x);
            // }

            string hash = it;
            sort(hash.begin(),hash.end());

            mp[hash].push_back(it);
        }
        vector<vector<string>> ans;

        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};