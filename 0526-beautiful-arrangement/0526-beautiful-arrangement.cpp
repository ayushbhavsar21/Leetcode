class Solution {
public:
    int countArrangement(int n) {
        
        vector<int> memo(1 << n, -1);
        return solve(1, n, 0, memo);
    }


    int solve(int i, int n, int used, vector<int>& memo) {
        
        if (i > n) {
            return 1;
        }

       
        if (memo[used] != -1) {
            return memo[used];
        }

        int count = 0;

        for (int num = 1; num <= n; num++) {
            int bit = 1 << (num - 1); 

            if ((used & bit) == 0 && (num % i == 0 || i % num == 0)) {
                count += solve(i + 1, n, used | bit, memo);
            }
        }

        
        memo[used] = count;
        return count;
    }
};
