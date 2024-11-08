class Solution {
public:
    bool solve(vector<int>& arr, int s, unordered_set<int>& st){
        if(arr[s] == 0)
            return true;
        if(s + arr[s] < arr.size() && st.count(s + arr[s]) == 0 ){
            st.insert(s + arr[s]);
            if(solve(arr , s + arr[s] , st))
                return true;
        }

        if(s - arr[s] >= 0 && st.count(s - arr[s]) == 0){
            st.insert(s - arr[s]);
            if(solve(arr , s - arr[s],st))
                return true;
        }
        return false;
    }

    bool canReach(vector<int>& arr, int s) {
        if(arr[s] == 0){
            return true;
        }

        unordered_set<int> st;
        return solve(arr , s , st);
    }
};