class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& s) {
        bool ok = 1;

        for(int i=0;i<9;i++){
            unordered_set<char> st;
            for(int j=0;j<9;j++){
                if(s[i][j] == '.'){}
                else if(st.count(s[i][j]) == 0)
                    st.insert(s[i][j]);
                else{
                    cout<<"row"<<endl;
                    return false;
                }
            }
        }
        for(int i=0;i<9;i++){
            unordered_set<char> st;
            for(int j=0;j<9;j++){                
                if(s[j][i] == '.'){}
                else if(st.count(s[j][i]) == 0)
                    st.insert(s[j][i]);
                else{
                    cout<<"col"<<endl;
                    return false;
                }
            }
        }

        int i =0,j=0;

        while(i < 9){
            j = 0;
            while(j < 9){
                int ix = i,jx = j;
                unordered_set<char> st;
                for(int ix = i;ix - i < 3;ix++ ){
                    for(int jx = j;jx - j < 3;jx++ ){
                        // cout<< ix<<" "<<jx<<endl;
                        if(s[ix][jx] == '.'){}
                        else if(st.count(s[ix][jx]) == 0)
                            st.insert(s[ix][jx]);
                        else{
                            cout<<"box"<<endl;
                            return false;
                        }
                    }
                }
                j += 3;
            }
            i += 3;
        }
        return true;
    }
};