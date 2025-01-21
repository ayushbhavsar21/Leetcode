class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < k)
            return -1;
        int max = *max_element(nums.begin(),nums.end());
        int min = *min_element(nums.begin(),nums.end());
        vector<int> v(max-min+1 , 0);
        for(auto it:nums){
            int x = it - min;
            v[x] ++;
        }
        int i = v.size()-1;
        cout<<i<<endl;
        while(k>0 && i>=0){
            k -= v[i];
            if(k<=0)
                return (i+min);
            i--;
        }
        return -1;
    }
};