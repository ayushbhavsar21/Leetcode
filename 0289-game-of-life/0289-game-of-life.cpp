class Solution {
public:
    int n,m;
    int func(int i,int j,vector<vector<int>>& v){
        int c = 0;
        int dx[8] = {1,1,1,0,-1,-1,-1,0};
        int dy[8] = {-1,0,1,1,1,0,-1,-1};

        for(int a=0;a<8;a++){
            int x = i + dx[a];
            int y = j + dy[a];

            if(x >=0 && x<n && y>=0 && y<m){
                if(v[x][y] == 1)
                    c++;
            }
        }
        return c;
    }
    void gameOfLife(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        vector<vector<int>> ans = v;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int live = func(i,j,v);
                // cout<<live<<endl;
                if(v[i][j] == 1){
                    if(live <2)
                        ans[i][j] = 0;
                    else if(live > 3)
                        ans[i][j] = 0;
                }
                else if(v[i][j] == 0){
                    if(live == 3)
                        ans[i][j] = 1;
                }
            }
        }
        v = ans;
    }
};