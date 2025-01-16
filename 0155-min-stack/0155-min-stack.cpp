class MinStack {
public:
    vector<int> v;
    vector<int> mini;
    MinStack() {
    }
    
    void push(int val) {
        v.push_back(val);
        if(mini.empty())
            mini.push_back(val);
        else{
            if(mini.back() >= val)
                mini.push_back(val);
        }
    }
    
    void pop() {
        if(!v.empty()){
            int x = v.back();
            v.pop_back();
            if(mini.back() == x)
                mini.pop_back();
        }
    }
    
    int top() {
        return v.back();
    }
    
    int getMin() {
        return mini.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */