class Solution {
public:
    int maxArea(vector<int>& v) {
        int n = v.size();
        int maxi = 0;
        int left = 0, right = n - 1;
        
        while (left < right) {
            int height = min(v[left], v[right]);
            int width = right - left;
            int area = height * width;
            maxi = max(maxi, area);
            
            if (v[left] < v[right])
                left++;
            else
                right--;
        }
        
        return maxi;
    }
};
