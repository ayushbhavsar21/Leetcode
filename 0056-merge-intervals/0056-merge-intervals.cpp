class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        int s = 0,e = 0;
        int n = v.size();
        for(int i=0;i<n;i++){
            if(i!=0 && e >= v[i][0]){
                e = max(e,v[i][1]);
            }    
            else{
                if(i!= 0)
                    ans.push_back({s,e});
                s = v[i][0];
                e = v[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};