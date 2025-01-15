class Solution {
public:
    int evalRPN(vector<string>& v) {
        stack<int> s;
        for(auto it:v){
            if(it == "+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x + y);
                // cout<<s.top()<<endl;
            }
            else if(it == "-"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y - x);
                // cout<<s.top()<<endl;
            }else if(it == "*"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(x * y);
                // cout<<s.top()<<endl;
            }else if(it == "/"){
                int x = s.top();
                s.pop();
                int y = s.top();
                s.pop();
                s.push(y / x);
                // cout<<s.top()<<endl;
            }
            else{
                int x = 0;
                int sign = 1;
                
                for(int i=0;i<it.size();i++){
                    if(i == 0 && it[0] == '-'){
                        sign = -1;
                        continue;
                    }
                    x = x*10 + (it[i] - '0');
                }
                x = sign*x;
                s.push(x);
                // cout<<"# "<<s.top()<<endl;
            }
        }
        int ans = s.top();
        s.pop();
        return ans;
    }
};