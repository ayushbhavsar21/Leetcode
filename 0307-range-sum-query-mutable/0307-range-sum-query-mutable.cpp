class NumArray {
public:
    vector<int> v;
    vector<int> sum;
    NumArray(vector<int>& nums) {
        v = nums;
        int s = 0;
        for(int i=0;i<v.size();i++){
            s += v[i];
            sum.push_back(s);
        }
    }
    
    void update(int idx, int val) {
        int d = v[idx] - val;
        v[idx] = val;
        for(int i=idx;i<v.size();i++){
            sum[i] -= d;
        }
    }
    
    int sumRange(int left, int right) {
        return sum[right] - sum[left] + v[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */