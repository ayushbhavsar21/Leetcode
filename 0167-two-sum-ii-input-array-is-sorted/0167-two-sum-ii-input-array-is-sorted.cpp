class Solution {
public:
    vector<int> twoSum(vector<int>& v, int t) {
        int n = v.size();
        int i=0,j= n-1;
        while(i<j){
            int x = t - v[i];
            if(x == v[j]){
                return {i+1 , j+1};
            }
            else if(x < v[j] ){
                j--;
            }
            else{
                i++;
            }
        }    
        return {-1,-1};
    }
};