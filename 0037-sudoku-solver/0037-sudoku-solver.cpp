class Solution {
public:
    vector<vector<int>> row;
    vector<vector<int>> col;
    vector<vector<vector<int>>> box;

    bool solve(int i, int j, vector<vector<char>>& s) {
        if (i == 9) return true;  
        if (j == 9) return solve(i + 1, 0, s);  
        if (s[i][j] != '.') return solve(i, j + 1, s); 

        for (int num = 0; num < 9; num++) {
            if (!row[i][num] && !col[j][num] && !box[i / 3][j / 3][num]) {
                s[i][j] = num + '1';
                row[i][num] = col[j][num] = box[i / 3][j / 3][num] = 1;

                if (solve(i, j + 1, s)) return true;

                s[i][j] = '.';  
                row[i][num] = col[j][num] = box[i / 3][j / 3][num] = 0;
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& s) {
        row = vector<vector<int>>(9, vector<int>(9, 0));
        col = vector<vector<int>>(9, vector<int>(9, 0));
        box = vector<vector<vector<int>>>(3, vector<vector<int>>(3, vector<int>(9, 0)));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (s[i][j] != '.') {
                    int x = s[i][j] - '1';
                    row[i][x] = 1;
                    col[j][x] = 1;
                    box[i / 3][j / 3][x] = 1;
                }
            }
        }
        
        solve(0, 0, s);
    }
};
