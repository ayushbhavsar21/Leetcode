struct Node {
    Node* list[26];
    bool end = false;
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& a) {
        Node* root = new Node();        
        Node* node = root;
            for (char ch : a[0]) {
                if (node->list[ch - 'a'] == NULL) {
                    node->list[ch - 'a'] = new Node();
                }
                node = node->list[ch - 'a'];
            }
            node->end = true;
        
        int ans = a[0].size();
        for(int i=1;i<a.size();i++){
            int c= 0;
            Node* node = root;
            for (char ch : a[i]) {
                if (node->list[ch - 'a'] == NULL) {
                    // cout<<"#"<<ans<<" "<<c<<endl;
                    // ans = min(c,ans);
                    break;
                }
                c++;
                node = node->list[ch - 'a'];
            }
            ans = min(c,ans);
        }
        // cout<<ans<<endl;
        string t = "";
        for(int i=0;i<ans;i++){
            t += a[0][i];
        }
        return t;
    }
};