
class Solution {
public:


    void solve(int i,string& s,string &t ,vector<string>& ans){
        if(i >= s.length()){
            ans.push_back(t);
            return ;
        }

        int x = s[i] - '0';

        if(x == 2){
            t.push_back('a');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('b');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('c');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }
        else if(x == 3){
            t.push_back('d');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('e');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('f');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }
        else if(x == 4){
            t.push_back('g');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('h');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('i');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }
         else if(x == 5){
            t.push_back('j');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('k');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('l');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        } else if(x == 6){
            t.push_back('m');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('n');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('o');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }
         else if(x == 7){
            t.push_back('p');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('q');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('r');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
            t.push_back('s');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        } else if(x == 8){
            t.push_back('t');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('u');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('v');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }
        else if(x == 9){
            t.push_back('w');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('x');
            solve(i+1 , s , t , ans);
            t.pop_back();
            t.push_back('y');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
            t.push_back('z');
            solve(i+1 , s , t , ans);
            t.pop_back(); 
        }

    }
    vector<string> letterCombinations(string s) {
        int n = s.length();
        vector<string> ans;
        if(n == 0)
            return ans;

        string t ="";
        solve(0 , s , t , ans);
        return ans;        
    }
};