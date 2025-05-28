class Solution {
public:
    int n;
    bool check(int x,int y,vector<string>& v){
        int n = v.size();
        for(int i=0;i<n;i++){
            if(i == y) continue;
            if(v[x][i] == 'Q') return 0;
        }

        for(int i=0;i<n;i++){
            if(i == x) continue;

            if(v[i][y] == 'Q') return 0;
        }
        int i = x, j = y;
        i--;
        j--;
        while(i>=0 && j>=0){
            if(v[i][j] == 'Q') return 0;
            i--;
            j--;
        }
        i = x , j = y;
        i--;
        j++;
        while(i>=0 && j<n){
            if(v[i][j] == 'Q') return 0;
            i--;
            j++;
        }
        i = x , j = y;
        i++;
        j--;
        while(j>=0 && i<n){
            if(v[i][j] == 'Q') return 0;
            i++;
            j--;
        }
        i = x , j = y;
        i++;
        j++;
        while(i<n && j<n){
            if(v[i][j] == 'Q') return 0;
            i++;
            j++;
        }

        return 1;
    }
    void solve(int i,vector<string>&v,vector<vector<string>>& ans){
        
        if(i == n){
            ans.push_back(v);
            return ;
        }

        
        for(int j=0;j<v.size();j++){
            v[i][j] = 'Q';
            if(check(i,j,v)){
                solve(i+1,v,ans);
            }
            v[i][j] ='.';
        }
        return ;
    }
    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<vector<string>> ans;
        string temp = "";
        for(int i=0;i<n;i++){
            temp.push_back('.');
        }
        vector<string> v(n ,temp) ;
        solve(0,v,ans);
        return ans;
    }
};