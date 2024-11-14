class Solution {
public:
    bool search(vector<int>& v, int t) {
        int n = v.size();
        int s = 0, e = n - 1, mid = 0;
        mid = s + (e - s) / 2;

        while (s <= e) {
            mid = s + (e - s) / 2;
            if (v[mid] == t)
                return true;
            if (v[s] == v[mid] && v[mid] == v[e]) {
                s = s + 1;
                e = e - 1;
                continue;
            }

            else if(v[s] <= v[mid] ){
                if(v[s] <= t && v[mid] > t)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
            else {
                if(v[mid]<t && v[e]>=t)
                    s = mid +1;
                else
                    e = mid -1;
            }
        }
        return false;
    }
};