class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> v(n, vector<int>(n,0));
        int top = 0,bottom = n-1,left =0 ,right = n-1;
        int c = 1;

        while(top<=bottom && left <= right){
            for (int i=left;i<=right;i++){
                v[top][i] = c;
                c++;
            }
            top++;

            for(int i=top;i<=bottom ;i++){
                v[i][right] = c;
                c++;
            }
            right--;

            for(int i = right;i>= left ;i--){
                v[bottom][i] = c;
                c++;
            }
            bottom--;

            for(int i = bottom ;i>= top ;i--){
                v[i][left] = c;
                c++;
            }
            left ++;
        }
        return v;
    }
};