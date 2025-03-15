class Solution {
public:
    int hIndex(vector<int>& v) {
        int n = v.size();
        int s = 0, e = n - 1;

        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (v[mid] >= (n - mid)) {
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return n - s;  
    }
};
