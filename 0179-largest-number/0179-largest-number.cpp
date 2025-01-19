static bool cmp(int &a,int &b){
    string s1 = to_string(a);
    string s2 = to_string(b);

    return s1+s2 > s2+s1;
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
        sort(nums.begin(),nums.end(),cmp);
        for(auto it:nums)
            ans += to_string(it);
        if(ans[0] == '0' && ans[ans.length()-1] == '0')
            return "0";
        return ans;
    }
};