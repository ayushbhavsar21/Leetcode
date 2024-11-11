class Solution {
public:
    void print(vector<vector<int>>& v){
        for(auto it:v){
            for(auto it2:it){
                cout<<it2<<" ";
            }cout<<endl;
        }
        cout<<"---------"<<endl;
    }
    void setZeroes(vector<vector<int>>& v) {
        int n = v.size();
        int m = v[0].size();
        bool ok1 =0;
        bool ok2 =0;
        for(int i=0;i<n;i++){
            if(v[i][0] == 0){
                ok1 = 1;
                break;
            }
        }
        for(int i=0;i<m;i++){
            if(v[0][i] == 0){
                ok2 = 1;
                break;
            }
        }

        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++ ){
                if(v[i][j] == 0){
                    v[0][j] = 0;
                    v[i][0] = 0;
                }
            }
        }
        // print(v);
        for(int i=1;i<n;i++){
            if(v[i][0] == 0){
                for(int j=1;j<m;j++){
                    v[i][j] = 0;
                }
            }
        }
        // print(v);

        for(int j = 1;j<m;j++){
            if(v[0][j] == 0){
                for(int i=1;i<n;i++){
                    v[i][j] = 0;
                }
            }
        }
        // print(v);

        if(ok1){
            for(int i=0;i<n;i++){
                v[i][0] = 0;
            }
        }
        if(ok2){
            for(int j=0;j<m;j++){
                v[0][j] =0;
            }
        }
        // print(v);

    }
};