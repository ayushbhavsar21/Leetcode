class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> st;
        unordered_set<string> st2;
        for(int i=0;i+10<=s.length();i++){
            string t =s.substr(i,10); 
            if(st.count(t))
                st2.insert(t);
            else
                st.insert(t);
        }
        st.clear();
        vector<string> ans;
        for(auto it:st2){
            ans.push_back(it);
        }
        st2.clear();
        return ans;
    }
};