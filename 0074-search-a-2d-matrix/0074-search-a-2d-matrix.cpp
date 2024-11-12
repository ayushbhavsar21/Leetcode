class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int t) {
        int n = v.size();
        int m = v[0].size();

        int s = 0,e = n-1;
        int mid = s + (e-s)/2 ;

        while(s<=e){
            mid = s + (e-s)/2 ;
            if(v[mid][m-1] == t) return true;
            else if(v[mid][m-1] > t){
                if(mid -1 > 0 && v[mid-1][m-1] < t){
                    break;
                }
                else e = mid-1;  
            } 
            else if(v[mid][m-1] < t) {
                if(mid +1 <n && v[mid+1][m-1] > t){
                    mid++;
                    break;
                }
                else
                    s = mid+1;
            }
        }
        s = 0,e = m-1;
        int ind = mid;
        while(s<=e){
            mid = s + (e-s)/2 ;
            if(v[ind][mid] == t){
                return true;
            }
            else if(v[ind][mid] > t){
                e = mid-1;
            }
            else{
                s = mid + 1;
            }
        }
        return false;
    }
};