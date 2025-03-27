class Solution {
public:
    vector<vector<int>> dp ;

    int solve(int i, int buy,vector<int>& prices ){

        if(i == prices.size())
            return 0;

        if(dp[i][buy] != -1)
            return dp[i][buy];
        
        int ans =0;        
        if(buy == 0){
            ans = max(0 + solve(i+1 , 0, prices ) , - prices[i] + solve(i+1 , 1,prices ) );
        }
        else if(buy == 1 ){
            ans = max(0 + solve(i+1 , 1 ,prices) , prices[i] + solve(i+1 , 2,prices ) );
        }
        else if(buy == 2){
            ans = solve(i+1 ,0 ,prices );
        }

        return dp[i][buy] = ans;
    }
    int maxProfit(vector<int>& prices) {
        
        dp = vector<vector<int>> (prices.size() , vector<int>(3 , -1 ) ) ;

        return solve(0,0,prices);
    }
};