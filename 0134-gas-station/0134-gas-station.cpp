class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int tg = accumulate(gas.begin(),gas.end(),0);
        int tc = accumulate(cost.begin(),cost.end(),0);
        if(tc > tg)
            return -1;
        int s =0;
        int c = 0;

        for(int i=0;i<n;i++){
            c += gas[i]-cost[i];
            if(c <0){
                s = i+1;
                c = 0;
            }
        }
        return s;
    }
};