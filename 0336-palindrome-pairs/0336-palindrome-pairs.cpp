bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> reversedMap;
        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); ++i) {
            string reversed = words[i];
            reverse(reversed.begin(), reversed.end());
            reversedMap[reversed] = i;
        }

        for (int i = 0; i < words.size(); ++i) {
            const string& word = words[i];
            int n = word.size();

            for (int j = 0; j <= n; ++j) {
                string left = word.substr(0, j);
                string right = word.substr(j);

                if (isPalindrome(left, 0, left.size() - 1)) {
                    auto it = reversedMap.find(right);
                    if (it != reversedMap.end() && it->second != i) {
                        ans.push_back({it->second, i});
                    }
                }

                if (j != n && isPalindrome(right, 0, right.size() - 1)) {
                    auto it = reversedMap.find(left);
                    if (it != reversedMap.end() && it->second != i) {
                        ans.push_back({i, it->second});
                    }
                }
            }
        }

        return ans;
    }
};
