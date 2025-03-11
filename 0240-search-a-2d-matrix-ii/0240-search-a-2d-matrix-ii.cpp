class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int t) {
        int n = mat.size();
        int m = mat[0].size();
        int i = 0,j=m-1;

        while(i < n && j>=0){
            // cout<<mat[i][j]<<endl;
            if(mat[i][j] == t)
                return 1;
            else if(mat[i][j] > t){
                j--;
            }
            else
                i++;
        }
        return 0;

        
    }
};