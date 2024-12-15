class Solution {
public:
    bool solve(int m,int t,int used,vector<int>& memo){
        if(t <=0 )
            return false;

        if(memo[used] != -1)
            return memo[used];

        for(int i=1;i<=m;i++){
            int bit = 1<<i;

            if((used & bit) == 0)
                if(!solve(m , t-i ,used | bit,memo))
                    return memo[used] = 1;


        }
        return memo[used] = 0;
    }
    
    bool canIWin(int m, int t) {
        if(t == 0)
            return 1;
        if ((m*(m+1))/2 <t ) return false;

        vector<int> memo (1<<21 , -1);
        return solve(m , t , 0 , memo);
    }

};